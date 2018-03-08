// Just a simple test driver for the gallows
// $Revision: 1.1 $
//   $Log: gallowsTest.cpp,v $
//   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//   Initial revision
//
#include <iostream>
#include "term.h"
#include "gallows.h"

using namespace std;

int main()
{
    Gallows *g = new Gallows(10, 2);

    cout << clearScreen << cursorOff;
    cout.flush();
    g->display();

    for(int i=0; i<8; i++) {
        //wait for the user to press enter and then advance
        cin.get();
        g->advance();
    }

    delete g;

    //restore the terminal
    cout << normal << cursorOn << clearScreen << endl;

    return 0;
}
