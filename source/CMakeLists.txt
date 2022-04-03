cmake_minimum_required(VERSION 3.16)
project(ChessProject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_executable(test test.cpp)
add_executable(Convert logic/Converter.cpp)

target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/logic/headers)

add_subdirectory(${PROJECT_SOURCE_DIR}/logic)
target_link_libraries(test PUBLIC Logic)