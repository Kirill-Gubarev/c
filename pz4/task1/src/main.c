#include <stdio.h>

int isEOF(char* buf){
	return buf[0] == '\\' &&
		buf[1] == 'E' &&
		buf[2] == 'O' &&
		buf[3] == 'F';
}

int main(int argc, char* argv[]){
	FILE* file = fopen("file.txt", "w");
	
	if(file == NULL){
		fprintf(stderr, "file opening error");
		getchar();
		return 1;
	}

	char buf[64];
	while(fgets(buf, sizeof(buf), stdin) != NULL && !isEOF(buf)){
		fprintf(file, "%s", buf);
	}

	fclose(file);
	getchar();
	return 0;
}
