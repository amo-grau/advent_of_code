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

add_executable(Day3)
target_sources(Day3
    PRIVATE
        src/main.cpp
)
target_link_libraries(Day3
    PRIVATE
        Bank
)