#include "fractals.h"

int main(int argc, char **argv)
{
  //create the window
  Fractal_Window *window = new Fractal_Window();

  //let's run!
  window->show(argc, argv);
  return Fl::run();
}
