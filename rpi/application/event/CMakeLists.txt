add_library(EventQueue OBJECT EventQueue.cpp EventQueue.hpp)

add_library(EventMain EventHandler.cpp EventHandler.hpp EventMain.hpp EventMain.cpp $<TARGET_OBJECTS:EventQueue>)