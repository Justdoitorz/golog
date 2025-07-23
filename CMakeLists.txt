cmake_minimum_required(VERSION 3.10)

project(golog)

add_definitions(-D_GNU_SOURCE)
add_compile_options(-Wall)

add_library(golog STATIC golog.c)
target_include_directories(golog PUBLIC .)



