#include <stdio.h>
#include <stdlib.h>

void myErr(const char* message, FILE* file){
	if(file != NULL)
		fclose_h(file);
	fprintf(stderr, "%s", message);
	getchar();
	exit(1);
}

FILE* fopen_h(const char* name, const char* mode){
	FILE* file = fopen(name, mode);
	if(file == NULL)
		myErr("file opening error\n", NULL);
	return file;
}

void fclose_h(FILE* file){
	if(fclose(file) < 0)
		myErr("file closing error\n", NULL);
}

int main(int argc, char* argv[]){
	if(argc < 3)
		myErr("too few arguments", NULL);

	FILE* inputFile = fopen_h(argv[1], "r");
	FILE* outputFile = fopen_h(argv[2], "w");

	char c = 'm';
	int lineNumber = 1;
	while((c = fgetc(inputFile)) != EOF){
		if(c == '\n')
			lineNumber++;

		if(lineNumber % 3 == 0)
			fputc(c, outputFile);
	}
	
	if(c != '\n')
		fputc('\n', outputFile);

	fclose_h(inputFile);	
	fclose_h(outputFile);	
	getchar();
	return 0;
}
