#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

using std::cout, std::cin;

class Vector;

class Shape{
  private:
    static int Count;
    static int cap;

  public:

    static Shape** shapes;

    Shape();



    static void PrintCount(){
	    cout << Count << "\n";
	};

    static int GetCount() {return Count;}

    virtual ~Shape();

    virtual void Move (Vector& v) = 0;
	  virtual void Out() = 0;
	  virtual double Area() = 0; 

};


#endif