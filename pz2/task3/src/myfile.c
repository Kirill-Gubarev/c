#include "myfile.h"
#include <stdlib.h>
FileHandler* createFH(char* fileName){
    void* memory = malloc(sizeof(FileHandler) + sizeof(char) * 1024);
    if(memory == NULL){
        printf("malloc error");
        exit(1);
    }
    FileHandler* fh = memory;
    fh->buf = (char*)memory + sizeof(FileHandler);

    FILE* ptrW = NULL;
    FILE* ptrR = NULL;
    fh->name = fileName;
    fh->isOpen = 0b00000000;

    return fh;
}
FILE* openRead(FileHandler* fh){
    fh->ptrR = fopen(fh->name, "r");
    return fh->ptrR;
}
FILE* openWrite(FileHandler* fh){
    fh->ptrW = fopen(fh->name, "w");
    return fh->ptrW;
}
char* fhRead(FileHandler* fh, size_t size){
    fgets(fh->buf, size, fh->ptrR);
    if(fh->buf)
        fh->isOpen |= READ;
    return fh->buf;
}
void fhWrite(FileHandler* fh,const char* text){
    fputs(text, fh->ptrW);
    fh->isOpen |= WRITE;
}
void closeFH(FileHandler* fh){
    if(fh->isOpen & WRITE)
        fclose(fh->ptrW);
    if(fh->isOpen & READ)
        fclose(fh->ptrR);
    if(fh != NULL)
         free(fh);
}