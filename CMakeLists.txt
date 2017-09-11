cmake_minimum_required(VERSION 3.7)
project(apue_test)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        apue.h
        lib/error.c
        main.c)

add_executable(apue_test ${SOURCE_FILES})