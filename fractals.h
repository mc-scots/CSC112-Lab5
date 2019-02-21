#ifndef fractals_h
#define fractals_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>

/**
 * This class is a custom widget which draws one of three fractals
 */
class Fractal_Pane : public Fl_Widget
{
public:
  //simple empty constructor
  Fractal_Pane(int x, int y, int w, int h);

  //virtual override of the draw method
  virtual void draw();

  //set the fractal number
  virtual void select_fractal(int n);

private:
  void draw_fractal_1();
  void draw_fractal_2();
  void draw_fractal_3();
  int fractal_num;
};

/**
 This class draws a window which lets the user select between three fractals.
*/
class Fractal_Window 
{
public:
  //create the window
  Fractal_Window();

  //show the window
  void show(int argc, char **argv);
private:
  Fl_Double_Window *window;
  Fl_Button *fractal_one;
  Fl_Button *fractal_two;
  Fl_Button *fractal_three;
  Fractal_Pane *fractal;

  //call backs for the buttons
  static void cb_fractal_one(Fl_Button *button, void *data);
  static void cb_fractal_two(Fl_Button *button, void *data);
  static void cb_fractal_three(Fl_Button *button, void *data);
};
#endif
