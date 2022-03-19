cmake_minimum_required(VERSION 3.20)
project(ChessProject)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_executable(test test.cpp)

target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/logic/headers)

add_subdirectory(${PROJECT_SOURCE_DIR}/logic)
target_link_libraries(test PUBLIC Logic)