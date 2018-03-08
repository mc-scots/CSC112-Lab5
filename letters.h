// This is a widget for displaying guessed letters.
// $Revision: 1.1 $
//   $Log: letters.h,v $
//   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//   Initial revision
//
#ifndef LETTERS_H
#define LETTERS_H
#include <vector>
#include "widget.h"

class Letters : public Widget
{
public:
    Letters();
    Letters(int _x, int _y);

    //widget overloads
    virtual void handleEvent(Event *e);
    virtual void display();

    //the one thing we can do is make guesses!
    void guess(char c);

private:
    std::vector<bool> guessed;  //whether each letter has been guessed
};
#endif
