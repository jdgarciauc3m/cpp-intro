all: test

geom.o:	geom.cpp geom.h
	g++ geom.cpp -c -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra

test:	main.cpp geom.o
	g++ main.cpp geom.o -o test -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra
