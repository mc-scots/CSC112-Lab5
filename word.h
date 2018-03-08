// This is a widget for selecting and display a random word for
// hangman.
// $Revision: 1.1 $
//   $Log: word.h,v $
//   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//   Initial revision
//
#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>
#include "widget.h"

class Word : public Widget
{
public:
    Word();
    Word(int _x, int _y);
    
    //widget functions
    virtual void handleEvent(Event *e);
    virtual void display();
    
    //reset the word by selecting a new random word
    virtual void reset();
private:
    std::string secretWord;
    std::vector<bool> revealed;
    std::vector<std::string> wordList;
};

#endif