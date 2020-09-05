all: test

mes.o:	mes.cpp mes.h
	g++ mes.cpp -c -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra

fecha.o:	fecha.cpp fecha.h mes.h
	g++ fecha.cpp -c -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra

test:	main.cpp fecha.o mes.o
	g++ main.cpp fecha.o mes.o -o test -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra
