cmake_minimum_required(VERSION 4.2)
project(AdventOfCode)

enable_testing()

add_library(Bank)
target_sources(Bank
    PRIVATE
        src/Bank.cpp
        src/BankBuilder.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/Bank.h
            include/BankBuilder.h
)

add_subdirectory(test)