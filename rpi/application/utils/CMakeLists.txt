project(utils)

add_definitions("-std=c++14 -Ofast -fPIC")

aux_source_directory("${PROJECT_SOURCE_DIR}/Logger" LOGGER_SRC)
aux_source_directory("${PROJECT_SOURCE_DIR}/timeout_generator" TIMEOUT_GENERATOR_SRC)

add_library(${PROJECT_NAME} STATIC ${LOGGER_SRC} ${TIMEOUT_GENERATOR_SRC})
#target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/Logger")