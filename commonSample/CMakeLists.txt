cmake_minimum_required (VERSION 2.8)
project(commonSample)

# 빌드 상세 과정을 모두 출력하는 Makefile을 생성
set (CMAKE_VERBOSE_MAKEFILE true)

message(STATUS "\${PROJECT_NAME} = ${PROJECT_NAME}")
message(STATUS "\${CMAKE_CURRENT_SOURCE_DIR} = ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "\${CMAKE_CURRENT_BINARY_DIR} = ${CMAKE_CURRENT_BINARY_DIR}")

###
# 추가 포함 디렉토리 설정
### 
# pch
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Common/HncZLib)

set(CMAKE_CXX_FLAGS "-std=c++11")
add_subdirectory(Common)
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    
target_link_libraries(${PROJECT_NAME} Common)