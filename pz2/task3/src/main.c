#include <stdio.h>

int main(int argc, char* argv[]){
	FILE* fileCreator = fopen("file.txt","w");
	fclose(fileCreator);	
	getchar();
	return 0;
}
