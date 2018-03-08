// This is a widget for displaying guessed letters.
// $Revision: 1.1 $
//   $Log: letters.cpp,v $
//   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//   Initial revision
//
#include <iostream>
#include "term.h"
#include "letters.h"
#include "application.h"

using namespace std;

Letters::Letters() : guessed(26, false)
{
    //set dimensions
    width(13);
    height(2);
}


Letters::Letters(int _x, int _y) : Letters()
{
    //set coordinates
    x(_x);
    y(_y);
}


//widget overloads
void 
Letters::handleEvent(Event *e)
{
    KeyboardEvent *kb;

    //get the keyboard event and use it to make a guess
    if(e->type() == "keyboard") {
        kb = (KeyboardEvent*) e;
        guess(kb->printable());
    }
}


void 
Letters::display()
{
    //go to the first position
    cout << cursorPosition(x(), y());

    //go through the alphabet
    for(int i=0; i<26; i++) {
        //see if we need to go to the next row
        if(i==13) {
            cout << cursorPosition(x(), y()+1);
        }

        //display the letter if it has been guessed
        if(guessed[i]) {
            cout << char('A' + i);
        } else {
            cout << ' ';
        }
    }

    cout.flush();
}


//the one thing we can do is make guesses!
void 
Letters::guess(char c)
{
    c = toupper(c);

    //we don't care about non letters!
    if(c < 'A' or c > 'Z') {
        return;
    }

    //update the guessed vector
    guessed[c - 'A'] = true;

    //redraw!
    display();
}
