TARGET = build/app

all: dirs $(TARGET)

dirs:
	mkdir -p obj build

$(TARGET): obj/main.o
	gcc -w -o $(TARGET) obj/main.o

obj/main.o: src/main.c
	gcc -w -o obj/main.o -c src/main.c

clean:
	rm -rf obj/* build/*
