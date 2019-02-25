/*! \main.cpp
    Declan Carter
    Feburary 2019
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
/*! \brief Semaphores Lab 2
  This lab uses a mutex and variables to implenment Semaphores to control two threads functions.
*/
/*! \class main
    \brief An Implementation of Threads Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions 
*/
/*! 
    \brief Displays a message first. 
*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
    /*! taskOne signal when it is finished, allowing taskTwo to run*/
  theSemaphore->Signal();
}
/*! 
    \brief  displays a message second.
*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
