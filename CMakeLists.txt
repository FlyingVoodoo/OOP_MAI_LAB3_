cmake_minimum_required(VERSION 3.10)
project(GeometryFigures VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(MAIN_SOURCE
    src/main.cpp
)

set(LIB_SOURCES
    src/point.cpp
    src/vector-points.cpp
    src/vector-figure.cpp
    src/figure.cpp
    src/rectangle.cpp
    src/rhombus.cpp
    src/trapezoid.cpp
)

add_executable(geometry_figures ${MAIN_SOURCE} ${LIB_SOURCES} ${HEADERS})
target_include_directories(geometry_figures PRIVATE include)
target_compile_features(geometry_figures PRIVATE cxx_std_20)

set(TEST_SOURCES
    test/test_point.cpp
    test/test_figures.cpp
    test/test_vectors.cpp
    test/main_test.cpp
)
add_executable(run_tests ${TEST_SOURCES} ${LIB_SOURCES})
target_include_directories(run_tests PRIVATE include)
target_compile_features(run_tests PRIVATE cxx_std_20)
target_link_libraries(run_tests PRIVATE GTest::gtest_main)

enable_testing()
add_test(NAME GeometryTests COMMAND run_tests)