TARGET = build/app

$(TARGET): dirs obj/main.o
	gcc -o $(TARGET) obj/main.o

obj/main.o: src/main.c
	gcc -o obj/main.o -c src/main.c

dirs:
	mkdir -p obj build

clean:
	rm -rf obj/* build/*
