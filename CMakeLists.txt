#[[Project is developed under MIT License]]

cmake_minimum_required(VERSION 3.10)
project(physics-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra --pedantic -std=c++2a")

set(MATH "src/math/matrix.hpp" "src/math/vector.hpp" )
set(ENGINE "src/engine/object.hpp" "/src/engine/object.cpp" "src/engine/physics_simulation.hpp" "src/engine/physics_simulation.hpp" )


set(MATH_TESTS "test/math/matrix_tests.cpp" "test/math/vector_tests.cpp")
set(ENGINE_TESTS "test/engine/object_tests.cpp" "test/engine/physics_simulation_tests.cpp" )


add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_compile_options()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

include_directories(src)
add_executable(APP src/main.cpp ${MATH} ${ENGINE})
set_target_properties(APP PROPERTIES LINKER_LANGUAGE CXX)

include_directories(src)
add_executable(TEST_SUITE ${MATH_TESTS} ${ENGINE_TESTS})
set_target_properties(TEST_SUITE PROPERTIES LINKER_LANGUAGE CXX)


enable_testing()
find_package(GTest)

target_link_libraries(
  TEST_SUITE
  GTest::Main
)

include(GoogleTest)
gtest_discover_tests(TEST_SUITE)
