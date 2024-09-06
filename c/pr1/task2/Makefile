TARGET = build/app
LIB_DIR = ../lib/
LIB_BUILD = ../lib/build
LIB_INCLUDE = ../lib/src

$(TARGET): obj/main.o $(LIB_BUILD)/libutils.a
	mkdir -p build
	gcc -o $(TARGET) obj/main.o $(LIB_BUILD)/libutils.a

obj/main.o: $(LIB_INCLUDE)/utils.h src/main.c
	mkdir -p obj
	gcc -o obj/main.o -I$(LIB_INCLUDE) -c src/main.c

$(LIB_BUILD)/libutils.a:
	"$(MAKE)" -C $(LIB_DIR)

clean:
	rm -rf build/* obj/*

cleanAll: clean
	"$(MAKE)" -C $(LIB_DIR) cleanAll