#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	char* cwd = getcwd(NULL, 0);
	if(!cwd){
		fprintf(stderr, "getcwd error\n");
		getchar();
		return 1;
	}

	printf("cwd = %s\n", cwd);
	free(cwd);

	getchar();
	return 0;
}
