cmake_minimum_required(VERSION 3.16)
project(MainLib)
set(CMAKE_CXX_STANDARD 17)

set(SCRIPTS_LIB scripts/MenuScript.cpp
                scripts/GameScript.cpp
                scripts/ExitScript.cpp)

set(MAIN_LIB    Main.cpp)

add_library(Main SHARED ${SCRIPTS_LIB} ${MAIN_LIB})
target_link_libraries(Main Logic Interface)