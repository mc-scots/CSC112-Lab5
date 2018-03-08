## The Story of Ed

Ed was a big fan of the game "hangman". Unfortunately, Ed was in his mid
30's and none of his age peers seemed to like the game as much as he
did. So he set out to make a computer game so he could play all by
himself. Poking around his Linux system, he found the dictionary file
which is used by ispell to spell check text files. This file contained
all the words in the English language, even the ones that no one uses,
such as
"[catabaptist](https://www.merriam-webster.com/dictionary/catabaptist)".
He decided that armed with this, he should be able to create a nifty
program which used the widget library he had so much fun with back when
he took CSC112 at Maryville College.

He vaguely remembered something about the necessity of having a good
design, but he didn't quite remember how to properly carry out UML
modeling. Instead, he took out a sheet of paper and designed the game
screen, the gallows figure, and the sequence. Ed's design is shown in
the thumbnail on this page.

![Ed's Design](paperDesign.jpg
"Ed's Design")

Ed took his "design" and set out to build the things he would need. He
clearly knew that he would need the following:

  - Word - randomly choose a word from the "words" file. This widget
    draws blanks and correct letters.
  - Gallows - Show the hanging man in his current state.
  - Letters - Show all the guessed letters.

Ed then set out to code these widgets. He created each one, and created
a test program to test each one. Then he created a Makefile which
compiled all of this programs for him. After testing his widgets and
verifying that the worked correctly, he then set out to put his objects
together into a complete game.

When Ed tried to build the finished game, he got stuck\! His "design"
didn't give him enough information to really build the program. His
pieces worked, but he didn't have a way to make them work together\! If
only Ed had carried out a correct process\! Luckily, he has us, and
we're going to give him a good design.

## How to Play Hangman

Ok, so at this point, I should mention how this game is played. Hangman
is a letter guessing game, where you draw the a number of blanks
indicating the number of letters in the word. The other player then
guesses letters. If they guess a letter in the word, you write that
letter in every blank where it appears. If they guess incorrectly, you
draw a part of a stick figure hanging from a gallows. Once the stick
figure is complete, the guesser loses. Now that I think about it, this
bit of innocent childhood fun is kind of dark and chilling. What's wrong
with us?\! Anyway, let's continue\! If the word is complete, the guesser
wins.

There are many variants of how to draw the stick figure, but typically
it consists of 6 parts in this order:

1.  head
2.  body
3.  left arm
4.  right arm
5.  left leg
6.  right leg

Some people, including Ed, draw a face on the figure when the right leg
is drawn. Ed's attempt at implementing the game does this too\!

## Your Task

Look at the code in the lab4 folder. This code contains Ed's original
code, along with all his test programs. Compile and run these programs
and make sure you understand what each item does. Now, follow through
with these steps:

1.  Draw class diagrams of Ed's Widgets as they currently exist.
2.  Draw a Use-Case diagram for the hangman game.
3.  Carry out the rest of the OOAD process, drawing the requisite
    diagrams.
4.  After you have completed and corrected Ed's design, upload png
    images of all your diagrams to your lab folder.

You will be graded on how well you model the task. Remember to adhere to
good OOP principles. You'll want to put a lot of effort into this
because your next programming assignment will be to modify Ed's code and
produce the fully integrated game.
