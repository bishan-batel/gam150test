//
// Created by bishan_ on 12/1/23.
//

#include "core/SceneTree.hpp"

#include <cassert>
#include <chrono>
#include <thread>
#include <utility>

#include <GL/glew.h>

#include "local/iso_test.hpp"
#include "local/sdl_test.hpp"


namespace bcake {
  std::unique_ptr<SceneTree> SceneTree::build_singleton() {
    auto tree = std::unique_ptr<SceneTree>(new SceneTree());
    return std::move(tree);
  }


  SceneTree::SceneTree() :
    window_size(vec2i(1000, 1000)) {

    to_render.clear();


    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("bruh", 0, 0, window_size.w, window_size.h, SDL_WINDOW_OPENGL);

    assert(window);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    gl_context = SDL_GL_CreateContext(window);

    if (!gl_context)
      std::cerr << "Failed to create GL Context" << std::endl;

    SDL_GL_MakeCurrent(window, gl_context);

    if (glewInit() != GLEW_OK) {
      std::cerr << "Failed to initialise GLEW" << std::endl;
    }

    glAlphaFunc(GL_GREATER, 0.5);
    glEnable(GL_ALPHA_TEST);

    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    root = std::make_unique<SDLTest>();
    root->tree = this;
    root->inside_tree = true;
    root->initialise();
    last_process_frame = std::chrono::system_clock::now().time_since_epoch();
  }

  void SceneTree::process_input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_WINDOWEVENT: {

        switch (event.window.event) {
        case SDL_WINDOWEVENT_RESIZED: {
          SDL_GetWindowSize(window, &window_size.w, &window_size.h);
          break;
        }
        default: ;
        }
        break;
      }
      default: ;
      }
    }
  }


  void SceneTree::update() {
    using namespace std::chrono;

    process_input();

    const auto per_frame = 1s / target_frame_rate;
    const auto now = system_clock::now().time_since_epoch();

    if (now - last_process_frame < per_frame)
      return;

    root->process_recurse(duration_cast<duration<f32>>(now - last_process_frame).count());


    post_frame();

    render();

    last_process_frame = now;
    std::this_thread::sleep_for(per_frame);
  }


  void SceneTree::render() const {
    // glBindFramebuffer(GL_FRAMEBUFFER, screen.fbo);
    glViewport(0, 0, window_size.w, window_size.y);
    glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glOrtho(-100.f, 100.f, -100.f, 100.f, 0.1f, 100.f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    for (const auto &node : to_render) {
      node->render();
    }

    SDL_GL_SwapWindow(window);
  }

  void SceneTree::post_frame() {
    while (!queued_to_initialise.empty()) {
      queued_to_initialise.front()->initialise();
      queued_to_initialise.pop();
    }

    // process deletion queue
    while (not queued_to_delete.empty()) {
      const std::unique_ptr<Node> to_delete = std::move(queued_to_delete.front());
      to_delete->free();
      queued_to_delete.pop();
    }

    if (not queued_next_scene)
      return;

    root->free();
    root = std::move(*queued_next_scene);
    queued_next_scene = std::nullopt;

    root->tree = this;
    std::cout << root->tree << std::endl;
    root->inside_tree = true;

    root->initialise();
  }

  void SceneTree::full_shutdown() const {
    root->free();
  }


  void SceneTree::change_scene(std::unique_ptr<Node> node) {
    queued_next_scene = std::move(node);
  }
}
