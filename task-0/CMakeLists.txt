cmake_minimum_required(VERSION 3.1)

project(sparse)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Testing stuff from here on
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

set(main_test "${PROJECT_SOURCE_DIR}/test/rational_test.cpp")
add_executable(tests ${sources} ${main_test})
target_link_libraries(tests Boost::unit_test_framework)

enable_testing()
add_test(Rational tests)