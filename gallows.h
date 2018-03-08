// This is a widget which draws a hangman gallows.  
// It allows the figure to be advanced, one tortuous bit 
// at a time.
// $Revision: 1.1 $
//   $Log: gallows.h,v $
//   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//   Initial revision
//
#ifndef GALLOWS_H
#define GALLOWS_H
#include "widget.h"

class Gallows : public Widget
{
public:
    Gallows();
    Gallows(int _x, int _y);

    //overloads from the widget class
    virtual void handleEvent(Event *e);
    virtual void display();

    //hangman functions
    void advance();
    void drawHead();
    void drawBody();
    void drawLeftArm();
    void drawRightArm();
    void drawLeftLeg();
    void drawRightLeg();
    void drawFace();
private:
    int parts;
};
#endif
