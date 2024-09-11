TARGET = build/app

all: dir $(TARGET)

dir:
	mkdir -p build obj

$(TARGET): obj/main.o
	gcc -o $(TARGET) obj/main.o

obj/main.o: src/main.c
	gcc -o obj/main.o -c src/main.c

clean:
	rm -rf obj/* build/*