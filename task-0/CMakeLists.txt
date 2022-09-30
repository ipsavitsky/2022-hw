cmake_minimum_required(VERSION 3.1)

project(sparse)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(sparse ${sources})

# Testing stuff from here on
set(TEST_NAMES
    rational
    complex
)

# find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_subdirectory(external)

foreach(TEST_NAME ${TEST_NAMES})
    add_executable(${TEST_NAME} "${PROJECT_SOURCE_DIR}/test/${TEST_NAME}_test.cpp")
    target_link_libraries(${TEST_NAME} boost_unit_test_framework sparse)

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endforeach()

enable_testing()