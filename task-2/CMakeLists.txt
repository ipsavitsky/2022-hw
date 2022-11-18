cmake_minimum_required(3.22)
project(symb_math)

file(GLOB SOURCES src/*.cpp)


include_directories(include)
add_executable(symb_math ${SOURCES})
