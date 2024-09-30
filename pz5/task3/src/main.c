#include <stdio.h>
#include <stdlib.h>

void myErr(const char* message, FILE* file){
	if(file != NULL)
		fclose_h(file);
	fprintf(stderr, "%s", message);
	getchar();
	exit(1);
}

FILE* fopen_h(const char* fname, const char* mode){
	FILE* file = fopen(fname, mode);
	if(file == NULL)
		myErr("file opening erro\n", NULL);
	return file;
}

void fclose_h(FILE* file){
	if(fclose(file) < 0)
		myErr("file closing error\n", NULL);
}

int main(int argc, char* argv[]){
	if(argc < 3)
		myErr("too few arguments\n", NULL);

	FILE* reader_file = fopen_h(argv[1], "r");
	FILE* writer_file = fopen_h(argv[2], "w");

	char buf[64];
	while(fgets(buf, sizeof(buf), reader_file))
		fputs(buf, writer_file);

	fclose_h(reader_file);
	fclose_h(writer_file);
	getchar();
	return 0;
}
