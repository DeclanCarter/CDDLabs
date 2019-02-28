#Declan Carter February



CC=g++
CFLAGS= -std=c++11 -pthread

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o
	$(CC) -o barrier main.cpp Barrier.cpp Semaphore.cpp $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o
