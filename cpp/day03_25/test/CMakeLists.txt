add_executable(TestBank)
target_sources(TestBank
    PRIVATE
        TestBank.cpp
)

find_package(GTest REQUIRED)
target_link_libraries(TestBank
    PRIVATE
        Bank
        GTest::gtest_main
)   

gtest_discover_tests(TestBank)