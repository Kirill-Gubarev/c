#ifndef MYFILE_H
#define MYFILE_H

#include <stdio.h>
#include <stdint.h>

#define READ    0b00000010
#define WRITE   0b00000001

typedef struct {
    FILE* ptrW;
    FILE* ptrR;
    char* name;
    char* buf;
    uint8_t isOpen;//7 byte is read| 8 byte is write
} FileHandler;

FileHandler* createFH(char* fileName);
FILE* openRead(FileHandler* fh);
FILE* openWrite(FileHandler* fh);
char* fhRead(FileHandler* fh, size_t size);
void fhWrite(FileHandler* fh,const char* text);
void closeFH(FileHandler* fh);

#endif//MYFILE