project(event_machine)

include_directories("${PROJECT_SOURCE_DIR}")


find_package( OpenCV REQUIRED )
add_subdirectory(queue)
add_subdirectory(executors)

aux_source_directory("${PROJECT_SOURCE_DIR}/core" CORE_SRC)

add_library(${PROJECT_NAME} STATIC ${CORE_SRC} $<TARGET_OBJECTS:executors> $<TARGET_OBJECTS:devices>)
target_link_libraries(${PROJECT_NAME} PRIVATE queue nanny ${OpenCV_LIBS})
#target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}")