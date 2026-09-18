cmake_minimum_required(VERSION 3.16)
project(data_structures_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

find_package(GTest QUIET)

if(NOT GTest_FOUND)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

enable_testing()

add_executable(unit_tests
    tests/queue_test.cpp
    tests/heap_test.cpp
    tests/binary_tree_test.cpp
)

target_include_directories(unit_tests PRIVATE include)
target_link_libraries(unit_tests PRIVATE GTest::gtest_main GTest::gmock)

include(GoogleTest)
gtest_discover_tests(unit_tests)
