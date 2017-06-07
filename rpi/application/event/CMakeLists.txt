project(event)

include_directories(${PROJECT_SOURCE_DIR})

add_library(EventQueue OBJECT EventQueue.cpp)

add_library(EventMain EventHandler.cpp EventMain.cpp $<TARGET_OBJECTS:EventQueue>)
target_include_directories(EventMain PUBLIC "${PROJECT_SOURCE_DIR}")