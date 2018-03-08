// A test for the word widget
// $Revision: 1.1 $
//   $Log: wordTest.cpp,v $
//   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//   Initial revision
//
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "term.h"
#include "word.h"
#include "application.h"

int main()
{
    Word *w = new Word(2, 10);
    Application *a = new Application();
    
    //seed the random number generator
    srand(time(0));
    
    
    std::cout << clearScreen << cursorOff;
    
    //set up the application
    w->reset();
    a->child(w);
    
    a->eventLoop();
}