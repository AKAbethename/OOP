#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>

#include "Shape.hpp"

using namespace std;

class Vector: public Shape
{
private:
	double x, y;	// Координаты вектора на плоскости

	int bit = 0;

	int index;
	char symb = 'v';

	int r = 0;
    int c = 0;
    int v = 0;

	

//	static int Count;
public:

	static Vector im_vector_r;
	static Vector im_vector_v;
	static Vector im_vector_c;
	//========== Три конструктора
	Vector (double c1, double c2);
	Vector ();							// Default

//	~Vector();

	Vector (const Vector&);

	~Vector();
	
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

	bool operator==(const Vector&);

	Vector operator*(double);

	double operator*(Vector v2);

	char get_letter() const{return symb;}

	int get_r(){return r;}
    int get_c(){return c;}
    int get_v(){return v;}


//	static void PrintCount(){
//		cout << Count << "\n";
//	};
};

Vector operator*(const Vector& v, double k);

Vector operator*(double k, const Vector &v);



#endif