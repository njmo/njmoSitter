cpp = g++
CFLAGS = -Wall -g -std=c++14
INCLUDES += -I./inc
L_LIBS = -L$(PWD)/build/lib

# LFLAGS = -L../lib
LIBS =	-lpthread
ODIR = $(SOURCE_MAIN)/build/obj
# List of all source files
SRCS =	rpi.cpp

vpath %.cpp $(PWD)/application

${info $(PWD)/application}

include Make/*

BDIR = $(SOURCE_MAIN)/build/bin

_OBJS = $(notdir $(SRCS:.cpp=.o))
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

MAIN = $(SOURCE_MAIN)/build/bin/rpi

.PHONY: depend clean all

all: $(MAIN)

$(MAIN): $(OBJS)
	$(cpp) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(L_LIBS) $(LIBS) $(LFLAGS) $(LD_FLAGS)

$(ODIR)/%.o: %.cpp
	${info $< ---- $@}
	$(cpp) $(CFLAGS) $(LIBS) $(INCLUDES) -fPIC -c -o $@ $<
	

