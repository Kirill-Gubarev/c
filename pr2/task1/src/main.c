#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc < 2)
		return 2;

	//opening the file
	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd < 0) 
		myErr("file opening error", fd);
	
	//filling the file with a random odd numbers
	srand(time(NULL));
	printf("<<<<< %s >>>>>\n", argv[1]);
	for(int i = 0; i < 10; ++i){
		//random number
		int num = randOdd(-99, 100);
		printf("%d\n", num);
		
		//convert number to string
		char buf[13];
		int len = snprintf(buf, sizeof(buf), "%d\n", num);
		if(len < 0)
			myErr("snprintf error", fd);

		writeh(fd, buf, len);
	}
	writeh(fd, "\0", 1);
	
	printf("=== SEEK_SET 5 ===\n");
	lseek(fd, 5, SEEK_SET);
	printFile(fd);

	printf("=== SEEK_END -3 ===\n");
	lseek(fd, -3, SEEK_END);
	printFile(fd);

	printf("=== SEEK_CUR -8 ===\n");
	lseek(fd, -8, SEEK_CUR);
	printFile(fd);

	printf("=== SEEK_END 2 ===\n");
	lseek(fd, 2, SEEK_END);
	printFile(fd);

	//closing the file
	if(close(fd) < 0)
		myErr("file closing error", -1);

	if(main(argc - 1, argv + 1) == 2)
		getchar();
	return 0;
}
