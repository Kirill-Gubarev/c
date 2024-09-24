TARGET = build/app

$(TARGET): dirs obj/main.o
	gcc -o $(TARGET) obj/main.o

dirs:
	mkdir -p obj build

obj/main.o:
	gcc -o obj/main.o -c src/main.c

clean:
	rm -rf obj/* build/*
