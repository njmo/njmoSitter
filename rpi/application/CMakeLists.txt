cmake_minimum_required(VERSION 2.8.11)
project(application)

set(CMAKE_STANDARD_LIBRARIES ${CMAKE_STANDARD_LIBRARIES} utils pthread queue)

include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(utils)
#add_subdirectory(server)
add_subdirectory(testLibrary)
add_subdirectory(event)

add_definitions("-std=c++14 -Ofast -fPIC")

add_executable(${PROJECT_NAME} "rpi.cpp" "Nanny.cpp")

#target_link_libraries(${PROJECT_NAME} LINK_PUBLIC event_machine server testLibrary -pthread)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC queue event_machine testLibrary -pthread)