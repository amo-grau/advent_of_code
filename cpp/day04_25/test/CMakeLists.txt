add_executable(Day4Test)

target_sources(Day4Test
    PRIVATE
        day4_test.cpp
)

find_package(GTest REQUIRED)
target_link_libraries(Day4Test
    PRIVATE
        Day4    
        GTest::gtest_main
)

gtest_discover_tests(Day4Test)