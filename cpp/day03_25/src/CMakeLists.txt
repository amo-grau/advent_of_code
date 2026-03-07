add_library(Day03_25_lib)

target_sources(Day03_25_lib
    PRIVATE
        Day0325.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            Day0325.h
)


add_executable(Day03_25)

target_sources(Day03_25
    PRIVATE
        main.cpp
)

target_link_libraries(Day03_25
    PRIVATE
        Day03_25_lib
)