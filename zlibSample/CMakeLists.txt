cmake_minimum_required (VERSION 2.8)
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


# # set(EMSDK_FLAGS
# #         " -pthread -s USE_PTHREADS -s PTHREAD_POOL_SIZE=4 \
# #         -s INITIAL_MEMORY=128mb ")
# # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EMSDK_FLAGS}")
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EMSDK_FLAGS}")
# message(STATUS "\${EMCC_LINKER_FLAGS} = ${EMCC_LINKER_FLAGS}")
# message(STATUS "\${EMSDK_FLAGS} = ${EMSDK_FLAGS}")
# message(STATUS "\${USE_FLAGS} = ${USE_FLAGS}")
# # set(CMAKE_CXX_FLAGS "-std=c++11 -s USE_ZLIB=1")
# # set(EMCC_LINKER_FLAGS "-s USE_ZLIB=1")
# # set(USE_FLAGS "-s USE_ZLIB=1")
# target_link_libraries(zlibSample libz.a)