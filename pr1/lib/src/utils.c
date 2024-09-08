#include "utils.h"
#include <stdio.h>

void pause(){
	myPrint("Press enter to continue...");
    getchar();
    getchar();
}

void myPrint(const char* text){
	printf("%s\n", text);
	fflush(stdout);
}
void myPrintInt(const char *text, int num){
	printf("%s%d\n", text, num);
	fflush(stdout);
}
void myPrintFloat(const char *text, float num){
	printf("%s%f\n", text, num);
	fflush(stdout);
}
void myPrintDouble(const char *text, double num){
	printf("%s%lf\n", text, num);
	fflush(stdout);
}

int myScanInt(const char *text){
	printf("%s", text);
	fflush(stdout);
	int num;
	scanf("%d", &num);
	return num;
}
float myScanFloat(const char *text){
	printf("%s", text);
	fflush(stdout);
	float num;
	scanf("%f", &num);
	return num;
}
double myScanDouble(const char *text){
	printf("%s", text);
	fflush(stdout);
	double num;
	scanf("%lf", &num);
	return num;
}