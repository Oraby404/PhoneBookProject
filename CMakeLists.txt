cmake_minimum_required(VERSION 3.15)
project(PhoneBookProject C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(PhoneBookProject
    construct.c
    fileprocessing.c
    Header.h
    main.c
    modify.c
    search.c
    Sort.c)
