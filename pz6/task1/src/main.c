#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

const char* getFileType(struct stat* sb){
	switch(sb->st_mode & S_IFMT){
		case S_IFBLK: return "blocking node of the device"; break; 
		case S_IFCHR: return "text identifier of the device"; break;
		case S_IFDIR: return "directory"; break;
		case S_IFREG: return "regular file"; break;
		default: return "unknown type"; break;
	}	
}

int main(int argc, char* argv[]){
	if(argc < 2){
		fprintf(stderr, "too few arguments\n");
		return 2;
	}
	
	struct stat sb;
	int ret = stat(argv[1], &sb);

	if(ret){
		fprintf(stderr, "stat error\n");
		return 1;
	}

	printf("file: %s\n", argv[1]);
	printf("file size: %ld bytes\n", sb.st_size);
	printf("file type: %s\n", getFileType(&sb));
	
	char buf[20];
	struct tm* timeinfo = localtime(&sb.st_ctim.tv_sec);
	strftime(buf, sizeof(buf), "%b %d %H:%M", timeinfo);
	printf("change time: %s\n", buf);

	timeinfo = localtime(&sb.st_mtim.tv_sec);
	strftime(buf, sizeof(buf), "%b %d %H:%M", timeinfo);
	printf("modification time: %s\n", buf);

	getchar();
	return 0;
}
