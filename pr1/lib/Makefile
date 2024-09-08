TARGET = build/libutils.a

$(TARGET): obj/utils.o
	mkdir -p build
	ar rcs $(TARGET) obj/utils.o

obj/utils.o: src/utils.c src/utils.h
	mkdir -p obj
	gcc -o obj/utils.o -c src/utils.c

clean:
	rm -rf build/* obj/*

cleanAll: clean