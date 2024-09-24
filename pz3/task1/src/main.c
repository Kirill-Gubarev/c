#include <stdio.h>

int main(int argc, char* argv[]){
	FILE* file = fopen("file.txt","r");

	if(file == NULL){
		fprintf(stderr, "file opening error");
		getchar();
		return 1;
	}
	
	int count = 0;
	char buf[2];
	while(fgets(buf, 2, file) != NULL){
		printf("%s", buf);
		++count;
	}
	printf("number of iterations: %d", count);
	
	fclose(file);
	getchar();
	return 0;
}
