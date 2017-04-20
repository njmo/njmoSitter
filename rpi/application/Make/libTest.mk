LIB_CFLAGS = -Wall -g -std=c++14
LIB_LFLAGS = -shared
LIB_INCLUDES += -I./inc
LIB_ODIR = $(SOURCE_MAIN)/build/obj
cpp = g++

LIBS += -lTest

# List of all source files
LIBSERVER_SRC :=  

include $(SOURCE_MAIN)/application/testLibrary/Makefile.mk

# Object files defined from source files
LIB__OBJS = $(notdir $(LIBSERVER_SRC:.cpp=.o))
LIB_OBJS = $(patsubst %,$(LIB_ODIR)/%,$(LIB__OBJS))

LIB_MAIN = $(SOURCE_MAIN)/build/lib/libTest.so

.PHONY: depend clean all

all: $(LIB_MAIN)

$(LIB_MAIN): $(LIB_OBJS)
	$(cpp) $(LIB_CFLAGS) $(LIB_INCLUDES) -o $(LIB_MAIN) $(LIB_OBJS) $(LIB_LFLAGS) $(LIB_LD_FLAGS)