cmake_minimum_required(VERSION 3.1)

project(sparse)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(rational "${PROJECT_SOURCE_DIR}/src/rational/rational.cpp")
set(main_exec "${PROJECT_SOURCE_DIR}/src/main.cpp")

add_executable(main ${rational} ${main_exec})

# Testing stuff from here on
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

set(main_test "${PROJECT_SOURCE_DIR}/test/rational_test.cpp")
add_executable(tests ${rational} ${main_test})
target_link_libraries(tests Boost::unit_test_framework)

enable_testing()
add_test(Rational tests)