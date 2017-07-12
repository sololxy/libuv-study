cmake_minimum_required(VERSION 3.9)
PROJECT(test-libuv)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

SET(NODEJS_ROOT "C:/develop/node-8.x")
SET(NODEJS_DEPS "${NODEJS_ROOT}/deps")

include_directories(${NODEJS_DEPS}/gtest/include)
include_directories(${NODEJS_DEPS}/icu-small/source)
include_directories(${NODEJS_DEPS}/uv/include)
include_directories(${NODEJS_DEPS}/v8/include)
include_directories(${NODEJS_DEPS}/zlib)

link_directories(${NODEJS_ROOT}/Release)
link_directories(${NODEJS_ROOT}/Release/lib)

add_subdirectory(tty-gravity)
