cmake_minimum_required(VERSION 3.5)
project(zlibSample)

# 빌드 상세 과정을 모두 출력하는 Makefile을 생성
set (CMAKE_VERBOSE_MAKEFILE true)

message(STATUS "\${PROJECT_NAME} = ${PROJECT_NAME}")
message(STATUS "\${CMAKE_CURRENT_SOURCE_DIR} = ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "\${CMAKE_CURRENT_BINARY_DIR} = ${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "-std=c++11")
add_subdirectory(zlib "${CMAKE_CURRENT_BINARY_DIR}/zlib")

add_executable(zlibSample
    ${CMAKE_CURRENT_SOURCE_DIR}/pch.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HncZLib.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(zlibSample zlibstatic)