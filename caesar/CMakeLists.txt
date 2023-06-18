project (caesar)
cmake_minimum_required(VERSION 3.5.1)

add_definitions(-std=c++11 -O3)
file(GLOB SOURCES src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")
add_executable(${PROJECT_NAME} ${SOURCES})

# main이 없는 경우
# set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_FUNCTIONS=\"['_caesarEncrypt', '_caesarDecrypt']\"")
# set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "--no-entry -s STANDALONE_WASM=1 -s EXPORTED_FUNCTIONS=\"['_caesarEncrypt', '_caesarDecrypt']\"")
# set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-Wl,--no-entry, -s STANDALONE_WASM=1 -s EXPORTED_FUNCTIONS=\"['_caesarEncrypt', '_caesarDecrypt']\"")