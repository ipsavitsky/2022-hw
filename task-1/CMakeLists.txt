cmake_minimum_required(VERSION 3.22)

project(Scheduling VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(scheduling ${SOURCES})

add_executable(reducer reducer.cpp)
target_link_libraries(reducer scheduling)

add_executable(worker worker.cpp)
target_link_libraries(worker scheduling)
