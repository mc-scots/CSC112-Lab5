// This is a widget which draws a hangman gallows.  
// It allows the figure to be advanced, one tortuous bit 
// at a time.
// $Revision: 1.1 $
//   $Log: gallows.cpp,v $
//   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//   Initial revision
//
#include <iostream>
#include <vector>
#include "gallows.h"
#include "term.h"

using namespace std;

static vector<string> frame = {
    "    ##############   ",
    "     |      \\\\   #   ",
    "             \\\\  #   ",
    "              \\\\ #   ",
    "               \\\\#   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "                 #   ",
    "====================="
};

static vector<string> head = {
    " ----- ",
    "|     |",
    "|     |",
    " ----- "
};


static vector<string> face = {
    " ----- ",
    "| x x |",
    "|  _  |",
    " ----- "
};


Gallows::Gallows()
{
    //set width and height
    width(21);
    height(17);
    parts = 0;
}


Gallows::Gallows(int _x, int _y) : Gallows() 
{
    //set widget cooridnates
    x(_x);
    y(_y);
}


//overloads from the widget class
void 
Gallows::handleEvent(Event *e)
{
    //nothing to do here
}


void 
Gallows::display()
{
    int row=0;

    //draw the gallows frame
    for(auto itr = frame.begin(); itr!=frame.end(); itr++) {
        cout << cursorPosition(x(), y() + row++) << *itr;   
    }


    //draw the parts 
    if(parts >= 1) { 
        drawHead();
    }
    if(parts >= 2) { 
        drawBody();
    }
    if(parts >= 3) { 
        drawLeftArm();
    }
    if(parts >= 4) { 
        drawRightArm();
    }
    if(parts >= 5) { 
        drawLeftLeg();
    }
    if(parts >= 6) {
        drawRightLeg();
        drawFace();
    }

    cout.flush();
}


//hangman functions
void 
Gallows::advance()
{
    if(parts<6) parts++;
    if(parts == 1) { 
        drawHead();
    }
    if(parts == 2) { 
        drawBody();
    }
    if(parts == 3) { 
        drawLeftArm();
    }
    if(parts == 4) { 
        drawRightArm();
    }
    if(parts == 5) { 
        drawLeftLeg();
    }
    if(parts == 6) {
        drawRightLeg();
        drawFace();
    }

    cout.flush();
}


void 
Gallows::drawHead() 
{
    //the starting position of the head
    int row=y()+2;
    int col=x()+2;

    //loop through the rows of the head and print them
    for(auto itr=head.begin(); itr!=head.end(); itr++) {
        cout << cursorPosition(col, row++) << *itr;
    }
}


void 
Gallows::drawBody()
{
    //the starting position of the body
    int row = y()+6;
    int col = x()+5;

    //draw the body
    for(int i=0; i<6; i++) {
        cout << cursorPosition(col, row++) << '|';
    }
}


void 
Gallows::drawLeftArm()
{
    //the starting position of the left arm
    int row = y()+7;
    int col = x()+2;
    
    //draw the arm
    for(int i=0; i<2; i++) {
        cout << cursorPosition(col++, row++) << '\\';
    }
}


void 
Gallows::drawRightArm()
{
    //the starting position of the left arm
    int row = y()+7;
    int col = x()+8;
    
    //draw the arm
    for(int i=0; i<2; i++) {
        cout << cursorPosition(col--, row++) << '/';
    }
}


void 
Gallows::drawLeftLeg()
{
    //the starting position of the left arm
    int row = y()+12;
    int col = x()+4;
    
    //draw the arm
    for(int i=0; i<2; i++) {
        cout << cursorPosition(col--, row++) << '/';
    }
}


void 
Gallows::drawRightLeg()
{
    //the starting position of the left arm
    int row = y()+12;
    int col = x()+6;
    
    //draw the arm
    for(int i=0; i<2; i++) {
        cout << cursorPosition(col++, row++) << '\\';
    }
}


void 
Gallows::drawFace()
{
    //the starting position of the head
    int row=y()+2;
    int col=x()+2;

    //loop through the rows of the head and print them
    for(auto itr=face.begin(); itr!=face.end(); itr++) {
        cout << cursorPosition(col, row++) << *itr;
    }
}

