cmake_minimum_required(VERSION 3.24)
project(symb_math)

file(GLOB SOURCES src/*.cpp)


include_directories(include)
add_library(symb_math ${SOURCES})
