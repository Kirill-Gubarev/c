#include <stdio.h>
#include <math.h>
#include "include.h"
Point* scanPoint(){
    float x, y;
    printf("x = ");
    fflush(stdout);
    scanf("%f", &x);
    printf("x = %f y = ",x);
    fflush(stdout);
    scanf("%f", &y);
    return createPoint(x, y);
}
float distance(Point* p1, Point* p2){
    return sqrt(
        pow(getX(p2) - getX(p1), 2) +
        pow(getY(p2) - getY(p1), 2));
}
int main(int argc, char *argv[]){
    printf("enter the 2 points\n");
    Point* ep1 = scanPoint();
    Point* ep2 = scanPoint();
    printf("distance beetwen points: %f\n", distance(ep1, ep2));

    printf("===============\n");

    Point *p = createPoint(77, 123);
    printf("Point *p = createPoint(77, 123);\n");
    fflush(stdout);
    printPoint(p);

    float x = getX(p);
    printf("float x = getX(p); // %f\n", x);
    fflush(stdout);

    setY(p, 8888);
    printf("setY(p, 8888);\n");
    fflush(stdout);
    printPoint(p);

    freePoint(p);

    printf("Press enter to continue...\n");
    fflush(stdout);
    getchar();
    getchar();
    return 0;
}