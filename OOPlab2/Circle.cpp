#include "Circle.hpp"

#include "MyVector.h"

#define PI 3.1415

//Vector Vector::im_vector_c(-1, -1);

void Circle::Move(Vector& v){
    this->ptCntr = this->ptCntr + v;
}

void Circle::Out(){
    std::cout << "Circle (" << ptCntr.get_x() << ", " << ptCntr.get_y() << ", " << R << ")";
}

double Circle::Area(){
    return (PI * R * R);
}

Circle::Circle(double a, double b, double re): ptCntr(a, b), R(re), r(r_cnt), v(v_cnt), c(c_cnt) {Shape::c_cnt++;
    std::cout << "\ncircle is created\n";
std::cout << "\n\n\nMy r, c, v equal " << r << " " << c << " " << v << "\n\n"; ;}


Circle::~Circle(){
    std::cout << "\nWe want to delete elements " << r + c + v << ", " << r+c+v+1 << "\n\n";
    array_of_indexes[r+c+v] = 1;
    array_of_indexes[r+c+v+1] = 1;
    set_CountDel();
    set_CountDel();


}