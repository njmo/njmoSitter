cpp = g++
CFLAGS = -Wall -g -std=c++14
INCLUDES += -I./inc

# LFLAGS = -L../lib
LIBS =	-lpthread

# List of all source files
SRCS =	rpi.cpp	server/phoneThread.cpp

# Object files defined from source files
OBJS = $(SRCS:.cpp=.o)

# # define the executable file 
MAIN = rpi

#List of non-file based targets:
.PHONY: depend clean all

##  .DEFAULT_GOAL := all

# List of dependencies defined from list of object files
DEPS := $(OBJS:.o=.d)

all: $(MAIN)

-include $(DEPS)

$(MAIN): $(OBJS)
	$(cpp)	$(CFLAGS)	$(INCLUDES)	-o	$(MAIN)	$(OBJS)	$(LFLAGS)	$(LIBS)

#suffix replacement rule for building .o's from .cpp's
#build dependency files first, second line actually compiles into .o
.cpp.o:
	$(cpp) $(CFLAGS) $(INCLUDES) -c -MM -MF $(patsubst %.o,%.d,$@) $<
	$(cpp) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	
clean:
	rm -rf *.o rpi