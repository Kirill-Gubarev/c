TARGET = build/app
FLAGS += -w
all: dirs $(TARGET)

dirs:
	mkdir -p obj build

$(TARGET): obj/main.o
	gcc $(FLAGS) -o $(TARGET) obj/main.o

obj/main.o: src/main.c
	gcc $(FLAGS) -o obj/main.o -c src/main.c
	
clean:
	rm -rf build/* obj/*
