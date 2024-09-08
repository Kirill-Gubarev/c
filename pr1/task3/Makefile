TARGET = build/app

$(TARGET): obj/main.o
	mkdir -p build
	gcc -o $(TARGET) obj/main.o

obj/main.o: src/main.c
	mkdir -p obj
	gcc -o obj/main.o -c src/main.c

clean:
	rm -rf build/* obj/*

cleanAll: clean