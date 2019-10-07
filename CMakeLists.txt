cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_COVERAGE "Build coverage" OFF)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
  SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)

project(parser)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

hunter_add_package(GTest)
hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(Threads)

add_library(
  ${PROJECT_NAME}
  STATIC
  sources/json.cpp
  sources/Coms.cpp
)

add_executable(
  tests
  tests/test2.cpp
  tests/test1.cpp
)

add_executable(
	task2
	sources/parserjson.cpp
)
target_link_libraries(task2 ${PROJECT_NAME})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(
  tests
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${GTEST_ROOT}/include
)

target_link_libraries(
  tests
  ${CMAKE_THREAD_LIBS_INIT}
  GTest::main
  GTest::gtest
  nlohmann_json::nlohmann_json
  ${PROJECT_NAME}
)

enable_testing()
add_test(NAME unit_tests COMMAND tests)

if (BUILD_COVERAGE)
  set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
  find_package(codecov)
  add_coverage(${PROJECT_NAME})
  add_coverage(tests)
  list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/tests/*'")
  coverage_evaluate()
endif ()
