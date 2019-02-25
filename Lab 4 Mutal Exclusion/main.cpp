/*! Declan Carter
    February 2019
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
/*! \Mutual Exclusion Lab
  \mainpage Using a semaphore to lock the loop to stop other threads from being able to accessing it while another thread is currently using it. Once the thread has finished it signals to the next thread to continue. 
   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions 
*/
static const int num_threads = 100;
int sharedVariable=0;

/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

*/
/*!
    \brief displays a message that is split in to 2 sections to show how a rendezvous works
    firstSem sends a wait to lock the loop, not allowing any other thread to use the loop until 
    they are signaled.
*/
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){

  firstSem->Wait();
  for(int i=0;i<numUpdates;i++){      
      sharedVariable++;
  }
  firstSem->Signal();

}

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore(1));
  /**< Launch the threads  */
  for(std::thread& t: vt){
    t=std::thread(updateTask,aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
