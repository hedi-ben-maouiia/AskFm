CC=g++ 
C_FLAGS=-Wall -Wextra -pedantic -ggdb -o 
SRC_DIR=src
BUILD_DIR=build


ask: $(SRC_DIR)/ask.cpp
	$(CC) $(SRC_DIR)/ask.cpp $(C_FLAGS) $(BUILD_DIR)/ask
run: ask
	./build/ask
