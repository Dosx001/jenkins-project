cmake_minimum_required(VERSION 3.26...3.31.1)
project(jenkins-project VERSION 1.0.0)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-O1")

file(MAKE_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_library(math src/math.cpp)

file(MAKE_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} math)

add_custom_target(
  run
  COMMAND ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}
  DEPENDS ${PROJECT_NAME}
)

add_executable(test_math src/test_math.cpp)
target_link_libraries(test_math math ${Boost_LIBRARIES})

enable_testing()
set(CMAKE_CTEST_ARGUMENTS "--output-on-failure")
add_test(NAME test_math COMMAND test_math)

add_custom_target(
  tests
  COMMAND ${CMAKE_BINARY_DIR}/bin/test_math
  DEPENDS test_math
)
