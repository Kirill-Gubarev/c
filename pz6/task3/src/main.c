#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc < 2)
		return 2;

	if(rmdir(argv[1]) < 0){
		fprintf(stderr, "rmdir error\n");
		getchar();
		return 1;
	}
	
	if(main(argc -1, argv + 1) == 2)
		getchar();
	return 0;
}
