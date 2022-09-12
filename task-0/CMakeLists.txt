cmake_minimum_required(VERSION 3.1)

project(sparse)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE sources "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(main ${sources})