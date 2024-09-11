#include "myfile.h"
#include <stdlib.h>
static void checkFilePtr(const FILE* file,const char* message){
    if(!file){
        printf(message);
        getchar();
        exit(0);
    }
}

int main (int argc, char * argv[]){
    FileHandler* fh = createFH("file.txt");

    checkFilePtr(openRead(fh),"The file is not opened.\n");
    char* text = fhRead(fh, 1024);
    printf(text);

    checkFilePtr(openWrite(fh),"The file is not opened.\n");
    char str[1024];
    scanf("%s", str); 
    fhWrite(fh,str);
   
    closeFH(fh);

    fflush(stdout);
    getchar();
    return 0;
}