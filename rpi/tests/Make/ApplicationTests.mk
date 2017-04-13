TEST_LISTS = $(shell find ${TEST_DIR}/tests/ApplicationTests -name \*mk)


include $(TEST_LISTS)


#vpath %.cpp ${TEST_DIR}/tests/ApplicationTests

#SRCS += BasicTest.cpp