#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point{
  private:
    double x;
    double y;
  public:
    Point(double, double);
    void move_x(double);
    void move_y(double);
    void set_point(double, double);
    double get_x() const{return x;};
    double get_y() const{return y;};
    bool operator==(const Point& obj_cmp) const;
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    bool operator<(const Point& obj_cmp) const;
    bool operator>(const Point& obj_cmp) const;
    bool operator!=(const Point& obj_cmp) const;

    Point& operator=(const Point& obj_cmp);

    Point& operator++();



};

#endif