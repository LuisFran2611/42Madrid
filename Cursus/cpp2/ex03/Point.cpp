#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {}

Point::~Point() {}

Point &Point::operator=(Point const &rhs) {
    if (this != &rhs) {
        // _x and _y are const, so we can't assign them
    }
    return *this;
}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}
