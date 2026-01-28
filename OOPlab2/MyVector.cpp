#include "stdafx.h"
#include "MyVector.h"
using std::cout, std::cin;

#include "Shape.hpp"

//Vector im_vector_v(-1, -1);


Vector::Vector (double c1, double c2) : r(r_cnt), v(v_cnt), c(c_cnt)
{
	x=c1;   y=c2;
	std::cout << "vector is created\n";
	bit = 1;
	Shape::v_cnt++;
//	++Count;
	std::cout << "\n\n\nMy r, c, v equal " << r << " " << c << " " << v << "\n\n"; 
}

Vector::Vector (): r(r_cnt), v(v_cnt), c(c_cnt)
{
	x = y = 0.;
	bit = 1;
	Shape::v_cnt++;
//	++Count;
	std::cout << "\n\n\nMy r, c, v equal " << r << " " << c << " " << v << "\n\n"; 
 
}

void Vector::Out()
{
	cout << "\nVector:  x = " << x << ",  y = " << y << "\n";
}

//Vector::~Vector(){
//	--Count;
//}

//Vector im_vector(-1, -1);

//Shape* Shape::im_shape = &im_vector;

Vector::~Vector(){
//	Vector im_vector{-1, -1};
//	set_Count();  // пришлось поменять приватный спецификатор на защищенный в классе Vector
    array_of_indexes[r+c+v] = 1;
	set_CountDel();
//	shapes[r+c+v] = &im_vector;
	
}


//====== Переопределение операций =====//
Vector& Vector::operator= (const Vector& v)	// Присвоение
{
	if (this == &v)
		return *this;
	x = v.x;
	y = v.y;

	std::cout << "\n Отладочная печать: вызван оператор присваивания\n";
	return *this;
}

Vector::Vector (const Vector& M){
	x = M.x;
	y = M.y;
	std::cout << "\n Отладочная печать: вызван конструктор копирования\n";
}


Vector Vector::operator+(const Vector& M){
	Vector res(x + M.x, y + M.y);
	std::cout << "\n Отладочная печать: вызван оператор сложения\n";
	return res;
}

double Vector::operator!() const{
	return sqrt(x*x + y*y);
}

bool Vector::operator>(const Vector& M){
	double l1 = !(*this);
	double l2 = !(M);
	if(l1 > l2) return true;
	return false;
}

bool Vector::operator==(const Vector &M){
	double x1 = x;
	double y1 = y;
	double x2 = M.x;
	double y2 = M.y;
	if(abs(x2 - x1) < DBL_EPSILON && (abs(y2 - y1) < DBL_EPSILON)) return true;
	return false;
}


Vector Vector::operator*(double k){
	Vector res(x*k, y*k);
	return res;
}


Vector operator*(const Vector& v, double k){
	Vector res(v.get_x() * k, v.get_y() * k);
	return res;
}

Vector operator*(double k, const Vector &v){
	Vector res(v.get_x() * k, v.get_y() * k);
	return res;
}

double Vector::operator*(Vector v2){
	return x * v2.get_x() + y * v2.get_y();
}


void Vector::Move(Vector& v){
	x += v.get_x();
	y += v.get_y();
}



//static void Vector::PrintCount(){
//	cout << "\n Now there are " << Count << " vectors";
//}
