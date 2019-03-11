/*! Declan Carter
    February 2019
*/
#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 100;
int sharedVariable = 0;
/*! \fn barrierTask
    \brief An example of using a reusable barrier
    \mainpage Demonstrating a rusable barrier. Splits a message into two to show how a rendevous works.

*/
void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task   
    std::cout << "A"<< i;
    //Barrier
    theBarrier->wait();
    //Do second half of task
    std::cout<< "B" << i; 
  }
}

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  /**< Launch the threads  */
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
