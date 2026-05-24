cmake_minimum_required(VERSION 3.14)
project(libemula LANGUAGES C)

file(GLOB SOURCES "src/*.c")
add_library(libemula STATIC ${SOURCES})
include_directories(include)
