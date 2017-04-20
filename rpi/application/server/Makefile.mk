
#LIBS += -lpthread
#OBJS += phoneThread.o phoneThread.h

vpath %.cpp $(PWD)/application/server
INCLUDES += -I$(PWD)/application/server

LIBSERVER_SRC += phoneThread.cpp testSource.cpp