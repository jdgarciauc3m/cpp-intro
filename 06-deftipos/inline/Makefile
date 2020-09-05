all: test

f1.o:	f1.cpp
	g++ f1.cpp -c -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra

f2.o:	f2.cpp
	g++ f2.cpp -c -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra

test:	main.cpp f1.o f2.o
	g++ main.cpp f1.o f2.o -o test -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra
