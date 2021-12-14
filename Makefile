build: src/main.cpp src/window.cpp src/applicationWindow.cpp src/vertexBuffer.cpp src/vertexArrays.cpp
	g++ -g -lglfw -lglut -lGL -lGLEW -o main src/main.cpp src/window.cpp src/applicationWindow.cpp src/vertexBuffer.cpp src/vertexArrays.cpp src/shader.cpp src/model.cpp src/modelRenderer.cpp

run: build
	./main

default: build
