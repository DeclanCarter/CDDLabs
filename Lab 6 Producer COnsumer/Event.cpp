/*!Declan Carter 
   February 2019
*/

/*! \class Event.cpp
\brief Implemenation of the event
*/
#include "Event.h"
#include <stdlib.h>
#include <iostream>

Event::Event(){
    eric = 'a'+rand()%26;
    std::cout <<    eric ;
 };

bool Event::consume(){
    char betterEric = eric-32;
    std::cout << betterEric;
};
