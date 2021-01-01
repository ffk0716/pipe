cmake_minimum_required(VERSION 3.19)
project(pipeline)
enable_testing()

add_executable(p main.cxx)
add_test(NAME p COMMAND p)
