PROJECT(tests)
add_definitions("-std=c++14 -Ofast -fPIC")

add_subdirectory(googletest)

AUX_SOURCE_DIRECTORY("${PROJECT_SOURCE_DIR}/OtherBasicTest" OtherBasicTest_SOURCES)
AUX_SOURCE_DIRECTORY("${PROJECT_SOURCE_DIR}/OtherOtherBasicTest" OtherOtherBasicTest_SOURCES)

ADD_EXECUTABLE("${PROJECT_NAME}" "testMain.cpp" ${OtherBasicTest_SOURCES} ${OtherOtherBasicTest_SOURCES})
target_link_libraries("${PROJECT_NAME}" PRIVATE gmock gmock_main) 

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}" "${gmock_SOURCE_DIR}/include" "${gtest_SOURCE_DIR}/include")