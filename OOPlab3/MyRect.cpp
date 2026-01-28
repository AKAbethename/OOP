#include "MyRect.hpp"
#include <iostream>

Rect::Rect(const Vector& a, const Vector& b){
    ptLT = a;
    ptRB = b;

}

Rect::Rect(const Rect& M){
    ptLT = M.ptLT;
    ptRB = M.ptRB;
}

Rect& Rect::operator=(const Rect& M){
    if(this == &M) return *this;

    ptRB = M.ptRB;
    ptLT = M.ptLT;

    return *this;
}

Rect::Rect(int left, int top, int right, int bottom){
    Vector v1(left, top);
    std::cout << "vector is created\n";
    Vector v2(right, bottom);
    std::cout << "vector is created\n";
    ptLT = v1;
    ptRB = v2;
    std::cout << "rect is created\n";
}


void Rect::Inflate(double k){
    Vector new_L(ptLT.get_x() - k, ptLT.get_y()-k);
    Vector new_R(ptRB.get_x()+k, ptRB.get_y()+k);
    ptLT = new_L;
    ptRB = new_R;
}

void Rect::Inflate(double wid, double len){
    Vector new_L(ptLT.get_x() - wid, ptLT.get_y());
    Vector new_R(ptRB.get_x(), ptRB.get_y()+len);
    ptLT = new_L;
    ptRB = new_R;
}

void Rect::Inflate(int left, int right, int top, int bottom){
    Vector new_L(ptLT.get_x() - left, ptLT.get_y()-right);
    Vector new_R(ptRB.get_x()+top, ptRB.get_y()+bottom);
    ptLT = new_L;
    ptRB = new_R;
}

void Rect::Out(){
    std::cout << "Rect (" << ptLT.get_x() << ", " << ptLT.get_y() << ", " << ptRB.get_x()   << ", " << ptRB.get_y() << ")";
}

void Rect::Move(Vector& v){
    this->ptLT = this->ptLT + v;
    this->ptRB = this->ptRB + v;
}

double Rect::Area(){
    return ((ptRB.get_x() - ptLT.get_x()) * (ptRB.get_y() - ptLT.get_y()));
}