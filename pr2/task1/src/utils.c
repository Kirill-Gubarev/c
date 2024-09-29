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

int randOdd(int l, int r){
	int difRL = r - l;
	int num = rand() % difRL + l;
	if(num % 2 == 0)
		num = (num + 1) % difRL;
	return num;
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
	while(1){
		int numberBytes = readh(fd, buf, sizeof(buf) - 1);
		if(numberBytes == 0)
			break;
		buf[numberBytes] = '\0';
		printf("%s", buf);
	}
}
