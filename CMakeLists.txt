cmake_minimum_required(VERSION 3.26)
project(gam150test)


#include_directories(. inc)
include_directories(. inc)

set(CMAKE_CONFIGURATION_TYPES
        "Debug"
        "Release"
        CACHE STRING "" FORCE

)

find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 5.0
    )
    FetchContent_MakeAvailable(raylib)
endif ()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
            GIT_TAG v5.0.0
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif ()

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
        core/NodePath.cpp
        core/NodePath.hpp
        core/StringName.cpp
        core/StringName.hpp
        main.cpp
        core/Node.hpp
        math/vec3.hpp
        math/vec3.cpp
        nodes/sprite_node.cpp
        nodes/sprite_node.hpp
        local/iso_test.cpp
        local/iso_test.hpp
        core/resource/Texture.cpp
        core/resource/Texture.hpp
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)


#file(COPY ${CMAKE_CURRENT_LIST_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})