project(event)

include_directories(${PROJECT_SOURCE_DIR})

add_library(EventQueue EventQueue.cpp)
target_include_directories(EventQueue PUBLIC "${PROJECT_SOURCE_DIR}")

add_library(EventMain EventHandler.cpp EventMain.cpp)
target_link_libraries(EventMain PRIVATE EventQueue)
target_include_directories(EventMain PUBLIC "${PROJECT_SOURCE_DIR}")