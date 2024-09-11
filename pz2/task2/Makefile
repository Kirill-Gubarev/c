TARGET = build/app

$(TARGET): dir obj/main.o
	gcc -o $(TARGET) obj/main.o

dir:
	mkdir -p build obj

obj/main.o: src/main.c
	gcc -o obj/main.o -c src/main.c

clean:
	rm -rf build/* obj/*