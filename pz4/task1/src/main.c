#include <stdio.h>

int main(int argc, char* argv[]){
	FILE* file = fopen("file.txt", "w");
	
	if(file == NULL){
		fprintf(stderr, "file opening error");
		getchar();
		return 1;
	}

	char buf[64];
	while(fgets(buf, sizeof(buf), stdin) != NULL)
		fprintf(file, "%s", buf);
	
	fclose(file);
	getchar();
	return 0;
}
