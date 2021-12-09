build: main.cpp
	g++ -lglfw -lGL -lGLEW -o main main.cpp

run: build
	./main

default: build
