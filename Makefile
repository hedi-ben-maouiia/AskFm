CC=g++ 
C_FLAGS=-Wall -Wextra -pedantic -ggdb -lraylib -o 
SRC_FILES=ask.cpp questions.cpp users.cpp main.cpp
BUILD_DIR=build


ask: 
	$(CC) $(SRC_FILES) $(C_FLAGS) $(BUILD_DIR)/main
run:
	./build/main
clean:
	rm -rf $(BUILD_DIR)/*
