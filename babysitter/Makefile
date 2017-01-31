CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		babysitter.o

LIBS =

TARGET =	babysitter

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
