project(nanny)

add_definitions("-std=c++14 -Ofast -fPIC")

include_directories("${PROJECT_SOURCE_DIR}")

aux_source_directory("${PROJECT_SOURCE_DIR}" NANNY_SRC)

add_library(${PROJECT_NAME} STATIC ${NANNY_SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE queue utils)
