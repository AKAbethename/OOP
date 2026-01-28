#include "MyVector.h"

#include "Shape.hpp"

class Rect: public Shape{
  private:

    int bit = 0;

    char symb = 'r';
    int index;

    int r = 0;
    int c = 0;
    int v = 0;

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

    char get_letter() const{return symb;}

    int get_r(){return r;}
    int get_c(){return c;}
    int get_v(){return v;}

    ~Rect();

};