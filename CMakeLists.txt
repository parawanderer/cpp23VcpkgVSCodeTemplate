cmake_minimum_required(VERSION 3.10)

#region Project Setup
# Project config (Project name is 'HelloWorld')
project(HelloWorld LANGUAGES CXX)

set(PROJECT_EXECUTABLE_NAME "HelloWorld")
set(PROJECT_TEST_EXECUTABLE_NAME "HelloWorldTest")

# C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# debug setup
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -stdlib=libc++")
#endregion

#region Configuration: MacOS
# Use the llvm compiler from brew on MacOS (brew install llvm)
if(APPLE)
    set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm/bin/clang)
    set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm/bin/clang++)
endif()
#endregion


# =====  Dependencies  =====

find_package(fmt CONFIG REQUIRED)

# ------  test  ------
find_package(gtest CONFIG REQUIRED) # unit testing framework GoogleTest: https://google.github.io/googletest/quickstart-cmake.html
enable_testing()



# =====  Executable  =====
#region Executable: main
add_executable(
    ${PROJECT_EXECUTABLE_NAME}
    # files that are bundled into the executable:
    src/main.cpp
    src/mathutil.cpp
)

target_link_libraries(
    ${PROJECT_EXECUTABLE_NAME}
    PRIVATE
    fmt::fmt  # fmt dependency
)

#endregion

# ===== Test Executable =====
#region Executable: test
add_executable(
    ${PROJECT_TEST_EXECUTABLE_NAME}
    # main.cpp is not needed in the test executable
    # (GoogleTest provides a main function)
    # files that are bundled into the test executable:
    src/mathutil.cpp
    # test files:
    test/test_mathutil.cpp
)

target_include_directories(
    ${PROJECT_TEST_EXECUTABLE_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(
    ${PROJECT_TEST_EXECUTABLE_NAME}
    PRIVATE
    fmt::fmt  # fmt dependency
    GTest::gtest_main # googletest (gtest) dependencies
)
# GoogleTest extra
include(GoogleTest) # Mentioned in the docs: https://google.github.io/googletest/quickstart-cmake.html
gtest_discover_tests(${PROJECT_TEST_EXECUTABLE_NAME}) # ^

#endregion