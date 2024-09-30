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
	if(argc < 2)
		return 2;
	printf("<<<<< %s >>>>>\n", argv[1]);
	FILE* file = fopen_h(argv[1], "w");

	char buf[64];
	while(fgets(buf, sizeof(buf), stdin))
		fprintf(file, "%s", buf);
	clearerr(stdin);

	fclose_h(file);
	printf("===========\n");
	file = fopen_h(argv[1], "r");

	while(fgets(buf, sizeof(buf), file))
		fprintf(stdout, "%s", buf);

	fclose_h(file);
	if(main(argc - 1, argv + 1) == 2)
		getchar();

	return 0;
}
