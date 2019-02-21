CXXFLAGS=-g `fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags`
TARGETS=fractals

all: $(TARGETS)
fractals: fractals.o main.o
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
fractals.o: fractals.cpp fractals.h
main.o: main.cpp fractals.h
clean:
	rm -f *.o $(TARGETS)
