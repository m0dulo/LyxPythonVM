cmake_minimum_required(VERSION 3.0)

project(LyxPythonVM)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -w -msse3 -funroll-loops  -std=c++11 -O0 -pg" )
else()
    SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC -funroll-loops -w -std=c++11 -O2 -march=native" )
endif()

include_directories(src/)

set(SRCS src/main.cpp
    src/code/binaryFileParser.cpp
    src/code/codeObject.cpp
    src/object/lyxInteger.cpp
    src/object/lyxString.cpp
    src/util/arrayList.cpp)

add_executable(vm ${SRCS})