all: Board.cpp main.cpp Board.h
	g++ -c Board.cpp
	g++ main.cpp Board.o -o 2048
