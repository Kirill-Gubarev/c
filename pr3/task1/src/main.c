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
	if(argc < 2)
		return 2;

	FILE* file = fopen_h(argv[1], "w");
	printf("<<<<< %s >>>>>\n", argv[1]);

	char buf[64];
	while(fgets(buf, sizeof(buf), stdin) != NULL)
		fputs(buf, file);
	clearerr(stdin);

	fclose_h(file);
	printf("==========\n");
	file = fopen_h(argv[1], "r");
	
	while(fgets(buf, 3, file) != NULL)
		fputc(buf[1], stdout);
	if(buf[1] != '\n')
		printf("\n");

	fclose_h(file);	
	if(main(argc - 1, argv + 1) == 2)
		getchar();
	return 0;
}
