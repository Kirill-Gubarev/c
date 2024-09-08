#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdint.h>

typedef uint8_t Point;

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

Point* createPoint(float x, float y);
void freePoint(Point* p);

float getX(Point* p);
float getY(Point* p);
void setX(Point* p, float value);
void setY(Point* p, float value);

void printPoint(Point* p);

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//INCLUDE_H