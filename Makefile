CC=g++
CLFAGS= -Wall -Wextra -std=c++17 
SRC=src/main.cpp
TARGET=build/main

main: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean: 
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
