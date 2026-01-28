#include "Circle.hpp"

#include "MyVector.h"

#define PI 3.1415

void Circle::Move(Vector& v){
    this->ptCntr = this->ptCntr + v;
}

void Circle::Out(){
    std::cout << "Circle (" << ptCntr.get_x() << ", " << ptCntr.get_y() << ", " << R << ")";
}

double Circle::Area(){
    return (PI * R * R);
}

Circle::Circle(double a, double b, double r): R(r), ptCntr(a, b) {}