#ifndef POINT_H
#define POINT_H
#include <iostream>

namespace pt{
    struct Point2D{
        float x, y;
        Point2D(float x, float y);
    };
}
pt::Point2D operator+(const pt::Point2D& p1, const pt::Point2D& p2);
pt::Point2D operator-(const pt::Point2D& p1, const pt::Point2D& p2);
pt::Point2D operator*(const pt::Point2D& p1, const pt::Point2D& p2);
pt::Point2D operator/(const pt::Point2D& p1, const pt::Point2D& p2);

std::ostream &operator<<(std::ostream &cout, pt::Point2D &point);


#endif//POINT_H