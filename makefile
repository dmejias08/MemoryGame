make:
	g++ interface.cpp `wx-config --cxxflags --libs std` -o program
	g++ mainS.cpp  -o server

run:
	./program
	./server
