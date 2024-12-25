cmake_minimum_required(VERSION 3.30)
project( C)

set(CMAKE_C_STANDARD 11)

add_executable(demo main.c
        book.h
        reader.h
        search.h
)
