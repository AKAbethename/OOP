#include "MyVector.h"

#include "Shape.hpp"

class Rect: public Shape{
  private:
    Vector ptLT;
    Vector ptRB;

  public:

    Rect(const Vector&, const Vector&);
    Rect(const Rect&);

    Rect& operator=(const Rect& M);

    Rect(int, int, int, int);

    void Inflate(double k = 1);

    void Inflate(double wid, double len);

    void Inflate(int, int, int, int);

    void Out();

    void Move(Vector& v);

    double Area();

};