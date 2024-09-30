TARGET = build/app

all: dirs $(TARGET)

dirs:
	mkdir -p obj build

$(TARGET): obj/main.o obj/utils.o src/utils.h
	gcc -o $(TARGET) obj/main.o obj/utils.o

obj/main.o: src/main.c
	gcc -o obj/main.o -c src/main.c

obj/utils.o: src/utils.c
	gcc -o obj/utils.o -c src/utils.c

clean:
	rm -rf obj/* build/*
