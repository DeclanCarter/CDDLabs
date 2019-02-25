/*! Declan Carter
    February 2019
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>
/*! \mainpage Rendezvous Lab 3
  This lab demonstrates a rendezvous between two threads. Using semaphores the first thread waits for the second thread before continuing.
*/
/*!
    \brief An Implementation of a Rendezvous using Semaphores
   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads
*/
/*!
    \brief displays a message that is split in to 2 sections to show how a rendezvous works
    The first task arrives and sends a signal allowing the second task to continue.
*/
void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task One has arrived! "<< std::endl;
  //Rendezvous Point
  firstSem->Signal();
  secondSem->Wait();
  std::cout << "Task One has left!"<<std::endl;
}
/*! \brief displays a message that is split in to 2 sections to show how a rendezvous works.
    The second task arrives and sends a wait to the thread stopping if from continuing. Then it receives a signal from the other thread and is released.
*/
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task Two has arrived "<<std::endl;
  //Rendezvous
  secondSem->Signal();
  firstSem->Wait();
  std::cout << "Task Two has left "<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  int taskOneDelay=5;
  int taskTwoDelay=1;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2,taskTwoDelay);
  threadTwo=std::thread(taskOne,sem1,sem2,taskOneDelay);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
