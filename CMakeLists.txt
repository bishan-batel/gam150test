cmake_minimum_required(VERSION 3.26)
project(gam150test)

set(CMAKE_CXX_STANDARD 23)

include_directories(. inc)

set(CMAKE_CONFIGURATION_TYPES
        "Debug"
        "Release"
        CACHE STRING "" FORCE
)

add_executable(gam150test
        math/number.hpp
        math/vec2.cpp
        math/vec2.hp
        math/mat3.cpp
        math/mat3.hpp
        core/Node.cpp
        core/Node.hpp
        core/RootNode.cpp
        core/RootNode.hpp
        core/SceneTree.cpp
        core/SceneTree.hpp
        nodes/Node2D.cpp
        nodes/Node2D.hpp
        core/Engine.cpp
        core/Engine.hpp
        core/NodePath.cpp
        core/NodePath.hpp
        core/StringName.cpp
        core/StringName.hpp
        math/mat4.cpp
        math/mat4.hpp
        main.cpp
)

#if (DEBUG)
#
#endif ()