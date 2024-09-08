#include "point.h"

pt::Point2D::Point2D(float x, float y) : x(x), y(y) {};

pt::Point2D operator+(const pt::Point2D& p1, const pt::Point2D& p2){
    return pt::Point2D(p1.x + p2.x, p1.y + p2.y);
}
pt::Point2D operator-(const pt::Point2D& p1, const pt::Point2D& p2){
    return pt::Point2D(p1.x - p2.x, p1.y - p2.y);
}
pt::Point2D operator*(const pt::Point2D& p1, const pt::Point2D& p2){
    return pt::Point2D(p1.x * p2.x, p1.y * p2.y);
}
pt::Point2D operator/(const pt::Point2D& p1, const pt::Point2D& p2){
    return pt::Point2D(p1.x / p2.x, p1.y / p2.y);
}
std::ostream &operator<<(std::ostream &cout, pt::Point2D &point){
    cout << "X: " << point.x << ' ' << "Y: " << point.y;
    return cout;
}
