TARGET = build/app
SRC = src
LIB = lib
OBJ = obj
BUILD = build

$(TARGET): $(OBJ)/main.o $(LIB)/build/libpoint.a
	mkdir -p build
	g++ -o $(TARGET) $(OBJ)/main.o $(LIB)/build/libpoint.a

$(OBJ)/main.o: $(OBJ) $(LIB)/src/include.h $(SRC)/main.c
	gcc -o $(OBJ)/main.o -I$(LIB)/src/ -c $(SRC)/main.c 

$(OBJ):
	mkdir -p $(OBJ)

$(LIB)/build/libpoint.a:
	"$(MAKE)" -C lib/

clean:
	rm -f $(BUILD)/* $(OBJ)/*

cleanAll: clean
	"$(MAKE)" -C lib/ cleanAll