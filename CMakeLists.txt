cmake_minimum_required(VERSION 3.26)
project(gam150test)


include_directories(. inc)

set(CMAKE_CONFIGURATION_TYPES
        "Debug"
        "Release"
        CACHE STRING "" FORCE
)

find_package(SDL2 REQUIRED)
include_directories(gam150test ${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
include_directories(gam150test ${OPENGL_INCLUDE_DIR})

find_package(GLEW REQUIRED)
#include_directories(gam150test ${GLEW_INCLUDE_DIRS})

add_executable(gam150test
        math/number.hpp
        math/vec2.cpp
        math/vec2.hpp
        math/mat3.cpp
        math/mat3.hpp
        core/Node.cpp
        core/Node.hpp
        core/SceneTree.cpp
        core/SceneTree.hpp
        nodes/CanvasItem.cpp
        nodes/CanvasItem.hpp
        core/Engine.cpp
        core/Engine.hpp
        core/node_path.cpp
        core/node_path.hpp
        core/string_name.cpp
        core/string_name.hpp
        main.cpp
        core/Node.hpp
        math/vec3.hpp
        math/vec3.cpp
        nodes/sprite_node.cpp
        nodes/sprite_node.hpp
        local/iso_test.cpp
        local/iso_test.hpp
        core/resource/texture.cpp
        core/resource/texture.hpp
        core/resource/IManagedResource.cpp
        core/resource/IManagedResource.hpp
        math/vec2i.cpp
        math/vec2i.hpp
        math/color.cpp
        math/color.hpp
        local/sdl_test.cpp
        local/sdl_test.hpp
        renderer/shader.cpp
        renderer/shader.hpp
        math/vec3.cpp
        core/event.cpp
        core/event.hpp
)

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)
#
set(link_src "${CMAKE_SOURCE_DIR}/assets")
if (UNIX AND NOT APPLE)
    set(link_dst "${CMAKE_CURRENT_BINARY_DIR}/assets")
else ()
    set(link_dst "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/assets")
endif ()
add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD COMMAND ${CMAKE_COMMAND}
        -E create_symlink ${link_src} ${link_dst}
        DEPENDS ${link_dst}
        COMMENT "symbolic link ${link_src} => ${link_dst}"
)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)

target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} OpenGL::OpenGL ${GLEW_LIBRARIES})


#file(COPY ${CMAKE_CURRENT_LIST_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
