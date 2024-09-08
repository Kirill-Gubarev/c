#include "point.h"
#include "include.h"
Point* createPoint(float x, float y){
    return (Point *)(new pt::Point2D(x, y));
}
void printPoint(Point* p){
    std::cout << *(pt::Point2D *)p << std::endl;
}

void freePoint(Point* p){
    delete (pt::Point2D *)p;
}

float getX(Point* p){
    return ((pt::Point2D *)p)->x;
}
float getY(Point* p){
    return ((pt::Point2D *)p)->y;
}
void setX(Point* p, float value){
    ((pt::Point2D *)p)->x = value;
}
void setY(Point* p, float value){
    ((pt::Point2D *)p)->y = value;
}