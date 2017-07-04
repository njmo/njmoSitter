project(queue)

add_definitions("-std=c++14 -Ofast -fPIC")

aux_source_directory("${PROJECT_SOURCE_DIR}" QUEUE_SRC)

add_library(${PROJECT_NAME} STATIC ${QUEUE_SRC})
#target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}")