cmake_minimum_required(VERSION 3.10)

# Project config (Project name is 'HelloWorld')
project(HelloWorld LANGUAGES CXX)

# C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Use the llvm compiler from brew on MacOS (brew install llvm)
if(APPLE)
    set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm/bin/clang)
    set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm/bin/clang++)
endif()


# =====  Dependencies  =====
find_package(fmt CONFIG REQUIRED)


# =====  Executable  =====
add_executable(HelloWorld helloworld.cpp)

# =====  Link libraries  =====
target_link_libraries(
    HelloWorld
    PRIVATE
    fmt::fmt
)