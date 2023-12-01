cmake_minimum_required(VERSION 3.26)
project(gam150test)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API
        "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(gam150test
        main.cc
        number.h
        vec2.cpp
        vec2.h
        mat3.cpp
        mat3.h
        node.cpp
        node.h
        root_node.cpp
        root_node.hpp
        scene_tree.cpp
        scene_tree.hpp
)
