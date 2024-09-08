TARGET = build/libpoint.a
SRC = src
OBJ = obj
BUILD = build

$(TARGET): $(OBJ)/wrapper.o $(OBJ)/point.o
	mkdir -p build
	ar rcs -o $(TARGET) $(OBJ)/wrapper.o $(OBJ)/point.o

$(OBJ)/wrapper.o: $(OBJ)
	g++ -o $(OBJ)/wrapper.o -c $(SRC)/wrapper.cpp

$(OBJ)/point.o:
	g++ -o $(OBJ)/point.o -c $(SRC)/point.cpp

$(OBJ):
	mkdir -p obj
	
clean:
	rm -f $(BUILD)/* $(OBJ)/*

cleanAll: clean