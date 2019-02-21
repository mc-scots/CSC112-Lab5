#include <FL/fl_draw.H>
#include "fractals.h" 

//////////////////////////////////////////////////////////////////////
// Fractal_Pane
//////////////////////////////////////////////////////////////////////

//simple empty constructor
Fractal_Pane::Fractal_Pane(int x, int y, int w, int h) : Fl_Widget(x,y,w,h)
{
  //default to no fractal
  fractal_num = 0;
}

//virtual override of the draw method
void 
Fractal_Pane::draw()
{
  if(fractal_num == 1) {
    //draw fractal 1
    draw_fractal_1();
  } else if(fractal_num == 2) {
    //draw fractal 2
    draw_fractal_2();
  } else if(fractal_num == 3) {
    //draw fractal 3
    draw_fractal_3();
  } else {
    //handle the no fractal situation
    fl_color(FL_WHITE);
    fl_rectf(x(), y(), w(), h());
  }
}

//set the fractal number
void 
Fractal_Pane::select_fractal(int n)
{
  //set our fractal number and redraw
  this->fractal_num = n;
  redraw();
}

void 
Fractal_Pane::draw_fractal_1()
{
  //TODO: Actually draw the fractal, the following is a place holder
  fl_color(FL_RED);
  fl_rectf(x(), y(), w(), h());
}


void 
Fractal_Pane::draw_fractal_2()
{
  //TODO: Actually draw the fractal, the following is a place holder
  fl_color(FL_GREEN);
  fl_rectf(x(), y(), w(), h());
}


void 
Fractal_Pane::draw_fractal_3()
{
  //TODO: Actually draw the fractal, the following is a place holder
  fl_color(FL_BLUE);
  fl_rectf(x(), y(), w(), h());
}
 

//////////////////////////////////////////////////////////////////////
// Fractal_Window
//////////////////////////////////////////////////////////////////////

//create the window
Fractal_Window::Fractal_Window() {
  //start the window off
  window = new Fl_Double_Window(640, 480, "Fractals are Fun!");
  window->user_data((void*)(this));

  //set up the buttons and their callbacks
  fractal_one = new Fl_Button(145, 425, 115, 40, "Fractal 1");
  fractal_one->callback((Fl_Callback*)cb_fractal_one, this);
  fractal_two = new Fl_Button(275, 425, 115, 40, "Fractal 2");
  fractal_two->callback((Fl_Callback*)cb_fractal_two, this);
  fractal_three = new Fl_Button(405, 425, 115, 40, "Fractal 3");
  fractal_three->callback((Fl_Callback*)cb_fractal_three, this);

  //create the fractal pane
  fractal = new Fractal_Pane(5,5,window->w()-10, fractal_one->y()-10);

  //all done!
  window->end();
}  


//show the window
void 
Fractal_Window::show(int argc, char **argv)
{
  window->show(argc, argv);
}

//callbacks for the fractal buttons
void 
Fractal_Window::cb_fractal_one(Fl_Button *button, void *data)
{
  ((Fractal_Window*)data)->fractal->select_fractal(1);
}


void 
Fractal_Window::cb_fractal_two(Fl_Button *button, void *data)
{
  ((Fractal_Window*)data)->fractal->select_fractal(2);
}


void 
Fractal_Window::cb_fractal_three(Fl_Button *button, void *data)
{
  ((Fractal_Window*)data)->fractal->select_fractal(3);
}
