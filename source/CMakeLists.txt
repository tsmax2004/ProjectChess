cmake_minimum_required(VERSION 3.20)
project(ChessProject)
set(CMAKE_CXX_STANDARD 20)

add_executable(test test.cpp)
add_executable(Convert logic/Convert.cpp)

target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/logic/headers)
target_include_directories(Convert PUBLIC ${PROJECT_SOURCE_DIR}/logic/headers)

add_subdirectory(${PROJECT_SOURCE_DIR}/logic)
target_link_libraries(test PUBLIC Logic)
target_link_libraries(Convert PUBLIC Logic)