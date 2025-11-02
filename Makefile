CC=g++ 
C_FLAGS=-Wall -Wextra -pedantic -ggdb 
SRC_FILES=ask.cpp questions.cpp users.cpp
BUILD_DIR=build


ask: $(SRC_FILES) main.cpp
	$(CC) main.cpp $(SRC_FILES) $(C_FLAGS) -o $(BUILD_DIR)/main

test: $(SRC_FILES) test.cpp
	$(CC) test.cpp $(SRC_FILES) -o build/test 
	./build/test

run: 
	./build/main

g: 
	gdb ./build/main 
clean:
	rm -rf $(BUILD_DIR)/*
