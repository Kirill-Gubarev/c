#include "utils.h"

int main(int argc, char* argv[]){
	myPrint("INPUT");
	float a = myScanFloat("a = ");
	float b = myScanFloat("b = ");
	int c = myScanInt("c = ");
	int d = myScanInt("d = ");

	myPrint("==============================");
	a = a + b - 2.0;
	myPrint("a = a + b - 2;");
	myPrintDouble("a = ", a);

	myPrint("==============================");
	c = c + 1;
	myPrint("c = c + 1;");
	myPrintInt("c = ", c);

	myPrint("==============================");
	d = c - a + d;
	myPrint("d = c - a + d;");
	myPrintInt("d = ", d);

	myPrint("==============================");
	a = a * c;
	myPrint("a = a * c;");
	myPrintDouble("a = ", a);

	myPrint("==============================");
	c = c - 1;
	myPrint("c = c - 1;");
	myPrintInt("c = ", c);

	myPrint("==============================");
	a = a / 10;
	myPrint("a = a / 10;");
	myPrintDouble("a = ", a);

	myPrint("==============================");
	c = c / 2;
	myPrint("c = c / 2;");
	myPrintInt("c = ", c);

	myPrint("==============================");
	b = b - 1;
	myPrint("b = b - 1;");
	myPrintDouble("b = ", b);

	myPrint("==============================");
	d = d * (c + b + a);
	myPrint("d = d * (c + b + a);");
	myPrintInt("d = ", d);

	myPrint("OUTPUT");
	myPrintFloat("a = ", a);
	myPrintFloat("b = ", b);
	myPrintInt("c = ", c);
	myPrintInt("d = ", d);

	pause();
	return 0;
}