cmake_minimum_required(VERSION 2.8.9)
project(adt)
find_package (Threads)

file(GLOB SOURCES "source/src/*.cpp" "source/include/*.hpp" "example/*.cpp")
file(GLOB SOURCES_GTEST "source/src/*.cpp" "source/include/*.hpp" "test/*.cpp" "test/*.hpp")
list(REMOVE_ITEM SOURCES_GTEST ${CMAKE_CURRENT_SOURCE_DIR}/source/src/main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 ")

include_directories(
  ../deps/gtest-1.7.0/include
  ../deps/gtest-1.7.0)

link_directories(../deps/gtest-1.7.0/src)
ADD_LIBRARY(gtest ../deps/gtest-1.7.0/src/gtest-all.cc)
ADD_LIBRARY(gtest_main ../deps/gtest-1.7.0/src/gtest_main.cc)

add_executable(ADT_test ${GTEST} ${SOURCES_GTEST})
add_executable(ADT_example ${SOURCES})
target_link_libraries(ADT_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})