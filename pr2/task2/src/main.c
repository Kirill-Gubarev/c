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
		myErr("file opening error", fd);
	
	printf("<<<<< %s >>>>>\n", argv[1]);
	char buf[1];
	
	lseek(fd, 5, SEEK_CUR);
	while(readh(fd, buf, 1) > 0){
		lseek(fd, -1, SEEK_CUR);

		if(writeh(fd, "\0", 1) == 0)
			break;
		lseek(fd, 4, SEEK_CUR);
	}
	lseek(fd, 0, SEEK_SET);
	printFile(fd);

	//closing the file
	if(close(fd) < 0)
		myErr("file closing error", -1);

	if(main(argc - 1, argv + 1) == 2)
		getchar();
	return 0;
}
