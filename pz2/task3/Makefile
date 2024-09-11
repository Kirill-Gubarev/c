TARGET = build/app

$(TARGET): dir obj/main.o obj/myfile.o
	gcc -o $(TARGET) obj/main.o obj/myfile.o

dir:
	mkdir -p build obj

obj/main.o: src/main.c src/myfile.h
	gcc -o obj/main.o -c src/main.c 

obj/myfile.o: src/myfile.c src/myfile.h
	gcc -o obj/myfile.o -c  src/myfile.c