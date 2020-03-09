all: rm compile

compile: point.o
	g++ -fno-elide-constructors -Wall main.cpp point.o -o main_point.exe

point.o:
	g++ -c -fno-elide-constructors -Wall point.cpp

rm:
	rm main_point.exe point.o