game:
	g++ interface.cpp `wx-config --cxxflags --libs std` -o program
	./program

:
	g++ mainS.cpp -o server
	./server
	

