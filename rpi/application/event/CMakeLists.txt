project(event)

include_directories(${PROJECT_SOURCE_DIR})

add_library(EventQueue OBJECT EventQueue.cpp EventQueue.hpp Event.hpp EEventType.hpp)

add_library(EventMain EventHandler.cpp EventHandler.hpp EventMain.hpp EventMain.cpp $<TARGET_OBJECTS:EventQueue>)