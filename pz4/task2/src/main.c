#include <stdio.h>

int main(int argc, char* argv[]){
	FILE* file = fopen("file.txt", "w");
	
	if(file == NULL){
		fprintf(stderr, "file opening error");
		getchar();
		return 1;
	}

	int a = 100;
	int b = 1720;
	int c = 1111111111;

	fprintf(file, "%d\n", a);
	fprintf(file, "%d\n", b);
	fprintf(file, "%d\n", c);

	fclose(file);
	getchar();
	return 0;
}
