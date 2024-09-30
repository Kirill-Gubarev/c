#ifndef UTILS_H
#define UTILS_H

void myErr(const char* message, int fd);
int randOdd(int l, int r);

int writeh(int fd, const char* buf, int len);
int readh(int fd, char* buf, int len);

void printFile(int fd);

#endif //UTILS_H
