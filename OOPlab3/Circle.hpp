#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

#include "MyVector.h"

class Circle: public Shape{
  private:
    double R;
    Vector ptCntr;

  public:

    Circle(double, double, double);

    void Move(Vector& v);
    void Out();
    double Area();


};


#endif