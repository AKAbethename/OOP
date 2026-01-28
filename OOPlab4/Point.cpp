#include "Point.hpp"
#include <float.h>

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

void Point::move_x(double d){
    x += d;
}

void Point::move_y(double d){
    y += d;
}

void Point::set_point(double x, double y){
    this->x = x;
    this->y = y;
}

#if 0

bool Point::operator==(const Point& obj_cmp) const{
//    if(x == obj_cmp.get_x() && y == obj_cmp.get_y()) return true;
    if(x - obj_cmp.get_x() < DBL_EPSILON && y - obj_cmp.get_y() < DBL_EPSILON) return true;
    return false;
}

#endif

bool Point::operator==(const Point& obj_cmp) const{
    return std::abs(x - obj_cmp.get_x()) < DBL_EPSILON && 
           std::abs(y - obj_cmp.get_y()) < DBL_EPSILON;
}

std::ostream& operator<<(std::ostream& os, const Point& p){
	os << p.x << "  " << p.y;
	return os;
}

/* bool Point::operator<(const Point& obj_cmp) const{
    double xx = obj_cmp.get_x();
    double yy = obj_cmp.get_y();
    if(x*x + y*y - (xx * xx + yy * yy)  > DBL_EPSILON) return false;
    if((xx * xx + yy * yy) - x*x + y*y > DBL_EPSILON) return true;
    return false;
} */

bool Point::operator<(const Point& obj_cmp) const{
    if(x < obj_cmp.get_x()) return true;
    if(x > obj_cmp.get_x()) return false;
    return y < obj_cmp.get_y();
}

bool Point::operator>(const Point& obj_cmp) const{
    return *this < obj_cmp;
}

/* Point& Point::operator=(Point& obj_cmp) const{
    if((abs(x - obj_cmp.get_x()) < DBL_EPSILON) && (abs(y - obj_cmp.get_y()) < DBL_EPSILON)) return;
    this->x = obj_cmp.get_x();
    y = obj_cmp.get_y();
    return *this;
} */

// ПРАВИЛЬНАЯ реализация оператора присваивания
Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Point::operator!=(const Point& obj_cmp) const{
    if(*this == obj_cmp) return false;
    return true;
}

Point& Point::operator++(){
    x++;
    y++;
    return *this;
}