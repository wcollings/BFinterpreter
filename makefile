INC= parser.h interpreter.h
OBJ=parser.o interpreter.o main.o
CC=clang++
FLAGS= -std=c++17

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

all: $(OBJ)
	$(CC) -o brainfuck $^ $(FLAGS)
