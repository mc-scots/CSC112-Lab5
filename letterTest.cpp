// A simple test for the letter class
// $Revision: 1.1 $
//    $Log: letterTest.cpp,v $
//    Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//    Initial revision
//
#include <iostream>
#include "letters.h"
#include "widget.h"
#include "term.h"
#include "application.h"

using namespace std;

int main()
{
    Letters *guessedBoard = new Letters(5, 15);
    Application *app = new Application(); 

    app->child(guessedBoard);

    cout << clearScreen << cursorOff;
    cout.flush();
    app->eventLoop();
}
