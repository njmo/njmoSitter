#to make it running need to make trick
# sudo ldconfig and add folder lib to /etc/ld.so.conf

INCLUDES += -I./inc #-I../application/inc -I../application/server
CFLAGS = -Wall -g -std=c++14
LIBS=-L./lib
vpath %.cpp ../application/server ./PhoneConnection
LIBS_L=-lgmock_main -lgmock -lgtest_main -lgtest -lpthread -lgtest
LFLAGS = 

LD_FLAGS=-Wl,-R ./lib
cpp = g++

# List of all source files
SRCS =main.cpp	test.cpp 

# Object files defined from source files
OBJS = $(SRCS:.cpp=.o)

# # define the executable file 
MAIN = tests

#List of non-file based targets:
.PHONY: depend clean all

##  .DEFAULT_GOAL := all

# List of dependencies defined from list of object files
DEPS := $(OBJS:.o=.d)

all: $(MAIN)

-include $(DEPS)

$(MAIN): $(OBJS)
	$(cpp) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS) $(LIBS_L) $(LD_FLAGS)

#suffix replacement rule for building .o's from .cpp's
#build dependency files first, second line actually compiles into .o
.cpp.o:
	$(cpp) $(CFLAGS) $(INCLUDES) -c -MM -MF $(patsubst %.o,%.d,$@) $<
	${info $< --------- $@}
	$(cpp) $(CFLAGS) $(INCLUDES) -c -o $@ $<
clean:
	rm -rf *.o tests
