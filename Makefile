all: build run

build:
	g++ ./main.cc -o ./main

run:
	./main