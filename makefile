make:
	g++ interface.cpp `wx-config --cxxflags --libs std` -o program

run:
	./program

