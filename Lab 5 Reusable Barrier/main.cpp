/*! Declan Carter
    February 2019
*/
#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 100;
/*! \fn barrierTask
    \brief An example of using a reusable barrier
    \mainpage Demonstrating a rusable barrier

*/
void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task   
    std::cout << "A"<< i << std::endl; // added endl for clearer output
    //Barrier
    theBarrier->wait();
    //Do second half of task
    std::cout<< "B" << i << std::endl; 
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
  std::cout << "Game over" << std::endl;
  return 0;
}
