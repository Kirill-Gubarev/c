#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <locale.h>
int main(int argc, char* argv[]){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int fd = open("file.txt", O_RDONLY);
    if (fd == -1){
        printf("не удалось открыть файл, код ошибки %d\n", errno);
        exit(errno);
    }
    printf("Файл успешно открыт\n");
    if (close(fd) == -1){
        perror("Ошибка закрытия файла\n");
        exit(errno);
    }
    printf("Файл успешно закрыт!\n");

    printf("Press enter to continue...\n");
    fflush(stdout);
    getchar();
    return 0;
}
