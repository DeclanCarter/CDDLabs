#include "SafeBuffer.h"

/*! \class SafeBuffer
\brief Implementation of a SafeBuffer
 
*/
SafeBuffer::SafeBuffer() {
    theMutex = std::make_shared<Semaphore>(1);
    theSemaphore = std::make_shared<Semaphore>(0);
};
/*! \fn Push function adds events to the buffer */

int SafeBuffer::push(Event newEric) {
    theMutex->Wait();
    theData.push_back(newEric);
    int size = theData.size();
    theMutex->Signal();
    theSemaphore->Signal();
    return size;
} //push

/*! \fn Pop function removes events to the buffer */

Event SafeBuffer::pop() {
    theMutex->Wait();
    Event e=theData.back();
    theData.pop_back();
    theMutex->Signal();
    return e;
} //pop
