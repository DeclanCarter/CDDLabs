#Declan March
#Lab 6 makefile 

CC=g++
CFLAGS= -std=c++11 -pthread

%.o:%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: SafeBuffer.o Semaphore.o Event.o main.o Semaphore.o
	$(CC) -o producerCon SafeBuffer.cpp Semaphore.cpp Event.cpp main.cpp $(CFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN: 
	rm *.o

