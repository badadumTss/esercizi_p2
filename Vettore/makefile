all: vettore.o
	g++ -o main.exe main.cpp vettore.o -fno-elide-constructors -fno-implicit-templates

debug: vettore.o
	g++ -o main_debug.exe main.cpp vettore.o -g -fno-elide-constructors

vettore.o:
	g++ -c vettore.cpp

clear:
	rm vettore.o main*.exe