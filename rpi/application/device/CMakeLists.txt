project(devices)

add_definitions("-std=c++14 -Ofast -fPIC")

aux_source_directory("${PROJECT_SOURCE_DIR}" DEVICES_SRC)

add_library(${PROJECT_NAME} OBJECT ${DEVICES_SRC})