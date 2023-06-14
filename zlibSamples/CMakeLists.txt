cmake_minimum_required(VERSION 3.5)
project(zlibSample)

# 빌드 상세 과정을 모두 출력하는 Makefile을 생성
set (CMAKE_VERBOSE_MAKEFILE true)

# pch
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# Extern
set (Extern_zlib ${CMAKE_CURRENT_SOURCE_DIR}/zlib)
include_directories(${Extern_zlib})

# set(CMAKE_CXX_STANDARD 17)

# set(EMSDK_FLAGS
#         " -pthread -s USE_PTHREADS -s PTHREAD_POOL_SIZE=4 \
#         -s INITIAL_MEMORY=128mb ")

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EMSDK_FLAGS}")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EMSDK_FLAGS}")

set(CMAKE_CXX_FLAGS "-std=c++11")

add_subdirectory(zlib)

add_executable(zlibSample
    ${CMAKE_SOURCE_DIR}/pch.cpp
    ${CMAKE_SOURCE_DIR}/HncZLib.cpp
    ${CMAKE_SOURCE_DIR}/main.cpp)

# target_include_directories(zlibSample PUBLIC "Extern/zlib")
target_link_libraries(zlibSample zlibstatic)