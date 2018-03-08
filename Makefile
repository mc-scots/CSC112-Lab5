CC=g++
CXXFLAGS=-g --std=c++11
WIDGET=term.o application.o keystream.o widget.o
TARGETS=gallowsTest letterTest wordTest

all: $(TARGETS)
gallowsTest: $(WIDGET) gallows.o gallowsTest.o
letterTest: $(WIDGET) letterTest.o letters.o
wordTest: $(WIDGET) wordTest.o word.o
clean:
	rm -f *.o $(TARGETS)

# $Revision: 1.1 $
#   $Log: Makefile,v $
#   Revision 1.1  2017/03/08 18:19:18  1ea49c2b19284e86b645075d033e28d0
#   Initial revision
#
