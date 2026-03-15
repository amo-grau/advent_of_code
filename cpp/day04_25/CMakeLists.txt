cmake_minimum_required(VERSION 4.2)
project(Day4)

add_library(Day4)
target_sources(Day4
    PRIVATE
        src/Day4.cpp
    
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/Day4.h
)


add_subdirectory(test)