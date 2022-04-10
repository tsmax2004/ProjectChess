cmake_minimum_required(VERSION 3.16)
project(ChessProject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_executable(test test.cpp)

target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/logic/headers)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/main/headers)

add_subdirectory(${PROJECT_SOURCE_DIR}/logic)
target_link_libraries(test PUBLIC Logic)

add_subdirectory(${PROJECT_SOURCE_DIR}/interface)
target_link_libraries(test PUBLIC Interface)

add_subdirectory(${PROJECT_SOURCE_DIR}/main)
target_link_libraries(test PUBLIC Main)

add_subdirectory(${PROJECT_SOURCE_DIR}/actionlink)
target_link_libraries(test PUBLIC Actions)

