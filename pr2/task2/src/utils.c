#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>

void myErr(const char* message, int fd){
	if(fd >= 0)
		close(fd);
	fprintf(stderr, "%s", message);
	getchar();
	exit(1);
}

int writeh(int fd, const char* buf, int len){
	int numberBytes = write(fd, buf, len);
	if(numberBytes < 0) 
		myErr("file writing error", fd);
	return numberBytes;
}

int readh(int fd, char* buf, int len){
	int numberBytes = read(fd, buf, len);
	if(numberBytes < 0)
		myErr("file reading error", fd);
	return numberBytes;
}

void printFile(int fd){
	char buf[64];
	while(readh(fd, buf, sizeof(buf)))
		printf("%s", buf);
}
