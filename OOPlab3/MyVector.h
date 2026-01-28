#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>

#include "Shape.hpp"

using namespace std;

class Vector: public Shape
{
private:
	double x, y;	// Координаты вектора на плоскости

//	static int Count;
public:
	//========== Три конструктора
	Vector (double c1, double c2);
	Vector ();							// Default

//	~Vector();

	Vector (const Vector&);
	
	//====== Переопределение операций =====//
	Vector& operator= (const Vector& v);	// Присвоение
	void Out();

	void Move(Vector&);

	double Area(){return 0;};

	double get_x() const{return x;}
	double get_y() const{return y;}

	Vector operator+(const Vector&);

	double operator!() const;

	bool operator>(const Vector&);

	bool operator<(const Vector&);

	bool operator==(const Vector&);

	Vector operator*(double);

	double operator*(Vector v2);

	
	friend ostream& operator<<(std::ostream& os, const Vector& p);

	Vector& operator*();

//	static void PrintCount(){
//		cout << Count << "\n";
//	};
};

Vector operator*(const Vector& v, double k);

Vector operator*(double k, const Vector &v);




#endif