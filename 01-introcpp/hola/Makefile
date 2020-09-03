ALL= hola hola.ii hola.s hola.o hola.nm hola.nm.cpp

all: ${ALL}

clean:
	rm ${ALL}

hola:	hola.cpp
	g++ hola.cpp -o hola -Wall

hola.ii: hola.cpp
	g++ hola.cpp -E -o hola.ii

hola.s: hola.cpp
	g++ hola.cpp -S -o hola.s

hola.o: hola.cpp
	g++ hola.cpp -c -o hola.o

hola.nm: hola.o
	nm hola.o > hola.nm

hola.nm.cpp: hola.o
	nm hola.o | c++filt | fmt -s -w 100 > hola.nm.cpp
