cmake_minimum_required(VERSION 3.20)
project(MyTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest CONFIG REQUIRED)


file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp")

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(tests)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
