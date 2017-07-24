cmake_minimum_required(VERSION 2.8.11)
project(nannyplication)

add_definitions("-std=c++14 -Ofast -fPIC")

set(CMAKE_STANDARD_LIBRARIES ${CMAKE_STANDARD_LIBRARIES} utils pthread queue)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/interface")

add_subdirectory(utils)
add_subdirectory(testLibrary)
add_subdirectory(nanny)
add_subdirectory(device)
add_subdirectory(event)
add_subdirectory(server)


add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC queue event_machine testLibrary nanny server -pthread)
