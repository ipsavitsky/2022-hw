cmake_minimum_required(VERSION 3.22)
project(symb_math)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES src/*.cpp)


include_directories(include)
add_library(symb_math ${SOURCES})

set(INSTALL_GTEST OFF)
add_subdirectory(external/googletest)
enable_testing()

include_directories(SYSTEM
    ${gtest_SOURCE_DIR}
    ${gtest_SOURCE_DIR}/include)

file(GLOB test_cases tests/*.cpp)
foreach(case_file ${test_cases})
    get_filename_component( case_name ${case_file} NAME_WE )
    set (case_name test_${case_name})
    add_executable(${case_name} ${case_file})
    target_link_libraries(${case_name} ${PROJECT_NAME}
                          ${LINK_LIBS} gtest_main pthread)
    add_test(NAME ${case_name}
             COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${case_name}
             WORKING_DIRECTORY
             ${PROJECT_BINARY_DIR})
endforeach()
