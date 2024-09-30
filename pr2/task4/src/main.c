#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc < 2)
		return 2;

	//opening the file
	int fd = open(argv[1], O_RDWR, 0644);
	if(fd < 0) 
		myErr("file opening error\n", fd);
	
	printf("<<<<< %s >>>>>\n", argv[1]);

	int posA = -1;
	while(posA == -1){
		char buf[64];
		int numberBytes = readh(fd, buf, sizeof(buf) - 1);
		if (numberBytes == 0)
			break;

		for(int i = 0; i < numberBytes; ++i)
			if(buf[i] == 'A'){
				posA = lseek(fd, 0, SEEK_CUR) - numberBytes + i; 
				break;
			}
	}

	if(posA >= 0)	
		if(ftruncate(fd, posA) < 0)
			myErr("file truncation error\n", fd);

	lseek(fd, 0, SEEK_SET);
	printFile(fd);

	//closing the file
	if(close(fd) < 0)
		myErr("file closing error\n", -1);

	if(main(argc - 1, argv + 1) == 2)
		getchar();
	return 0;
}
