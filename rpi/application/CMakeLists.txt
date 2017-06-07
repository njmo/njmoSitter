cmake_minimum_required(VERSION 2.8.11)
project(application)

add_subdirectory(server)
add_subdirectory(testLibrary)
add_subdirectory(event)

include_directories("${PROJECT_SOURCE_DIR}")

add_definitions("-std=c++14 -Ofast -fPIC")

add_executable(${PROJECT_NAME} "rpi.cpp")

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC server testLibrary -pthread)