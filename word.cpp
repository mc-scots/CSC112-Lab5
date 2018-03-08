// This is a widget for selecting and display a random word for
// hangman.
// $Revision: 1.1 $
//   $Log: word.cpp,v $
//   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
//   Initial revision
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "word.h"
#include "application.h"
#include "term.h"


Word::Word()
{
    //set dimenisons
    width(41);
    height(1);
    
    //load the word list
    std::ifstream file("words");
    std::string s;
    
    while(file >> s) {
        wordList.push_back(s);
    }
    file.close();
}


Word::Word(int _x, int _y) : Word()
{
    //set the coordinates
    x(_x);
    y(_y);
}
    

//widget functions
void 
Word::handleEvent(Event *e)
{
    char c;
    
    //handle only keyboard events
    if(e->type() != "keyboard") {
        return;
    }
    c = ((KeyboardEvent*)e)->printable();
    
    //mark the instances of this letter as guessed
    for(int i=0; i<secretWord.length(); i++) {
        if(secretWord[i] == c) {
            revealed[i] = true;
        }
    }
    
    display();
}


void 
Word::display()
{
    //position this thing at the center
    int col = x() + width()/2 - secretWord.length();
    std::cout << cursorPosition(col, y());
    
    for(int i=0; i<secretWord.length(); i++) {
        if(revealed[i]) {
            std::cout << secretWord[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    
    std::cout.flush();
}
    

//reset the word by selecting a new random word
void 
Word::reset()
{
    clear();
    secretWord = wordList[std::rand() % wordList.size()];
    revealed = std::vector<bool>(secretWord.length(), false);
    display();
}