OUT=hw
CPP=g++
CPPFLAGS=-std=c++17 -g
LDFLAGS = -lpthread #-static

OBJS =  main.o net.o dev.o mon.o

all: $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(OUT) $(OBJS) $(LDFLAGS)

%.o:	%.cpp
	$(CPP) $(CPPFLAGS) -I. -c $<

clean:
	rm -f $(OUT) *.o
