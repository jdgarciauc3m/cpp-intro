all: test

fecha.o:	fecha.cpp fecha.h
	g++ fecha.cpp -c -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra

test:	main.cpp fecha.o
	g++ main.cpp fecha.o -o test -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra
