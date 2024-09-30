#include <stdio.h>
#include <stdlib.h>

void myErr(const char* message, FILE* file){
	if(file != NULL)
		fclose(file);
	fprintf(stderr, "%s", message);
	getchar();
	exit(1);
}

int main(int argc, char* argv[]){
	if(argc < 2)
		return 2;

	FILE* file = fopen(argv[1], "r");
	if(file == NULL)
		myErr("file opening error\n", file);

	char buf[64];
	while(fgets(buf, sizeof(buf), file))
		printf("%s", buf);

	if(fclose(file) < 0)
		myErr("file closing error\n", file);

	if(main(argc - 1, argv + 1) == 2)
		getchar();

	return 0;
}
