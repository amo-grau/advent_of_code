add_executable(TestDay03_25)

target_sources(TestDay03_25
    PRIVATE
        TestDay03_25.cpp
)

find_package(GTest REQUIRED)
target_link_libraries(TestDay03_25
    PRIVATE
        Day03_25_lib
        GTest::gtest_main
)   

gtest_discover_tests(TestDay03_25)