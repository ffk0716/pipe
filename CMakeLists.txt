cmake_minimum_required(VERSION 3.19)
project(pipeline)
enable_testing()

add_subdirectory(3rdparty)

add_executable(p main.cxx)
target_link_libraries(p gtest_main gtest)
add_test(NAME p COMMAND p)
