make:
	g++ image_tryout.cpp `wx-config --cxxflags --libs std` -o program
	

run:
	./program
