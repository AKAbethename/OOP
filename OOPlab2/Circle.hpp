#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

#include "MyVector.h"

class Circle: public Shape{
  private:
    

    char symb = 'c';

    int r = 0;
    int c = 0;
    int v = 0;

    double R;
    Vector ptCntr;

    int index = 0;

    int bit = 0;

  public:

    Circle(double, double, double);

    void Move(Vector& v);
    void Out();
    double Area();

    char get_letter() const{return symb;}

    int get_r(){return r;}
    int get_c(){return c;}
    int get_v(){return v;}

    ~Circle();


};


#endif