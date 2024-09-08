#ifndef UTILS_H
#define UTILS_H

void pause();

//prints
void myPrint(const char* text);
void myPrintInt(const char *text, int num);
void myPrintFloat(const char *text, float num);
void myPrintDouble(const char *text, double num);

//scanners
int myScanInt(const char *text);
float myScanFloat(const char *text);
double myScanDouble(const char *text);

#endif //UTILS_H