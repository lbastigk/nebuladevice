add_executable(nebuladevice_tests
    SmokeTest.cpp
)

target_link_libraries(nebuladevice_tests PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(nebuladevice_tests)
