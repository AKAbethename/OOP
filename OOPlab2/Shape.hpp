#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

using std::cout, std::cin;

class Vector;

class Shape{
  private:
    static int Count;
    static int cap;

    static int CountDel;

    static int K;


    static Shape im_shape;

    int bit;

    

  public:

    int index;

    static Shape** shapes;

    static int array_of_indexes[];

    static int r_cnt;
    static int c_cnt;
    static int v_cnt;

    Shape();

    static void set_CountDel(){CountDel += 1;}


    static void PrintCount(){
	    cout << Count << "\n";
	};

    static int GetCount() {return Count;}

    static int GetCountDel() {return CountDel;}

    static int GetCap() {return cap;}

    virtual ~Shape();

    virtual void Move (Vector& v) = 0;
	  virtual void Out() = 0;
	  virtual double Area() = 0;

    virtual char get_letter() const = 0;

};


#endif