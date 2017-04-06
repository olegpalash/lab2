all: lab1

lab1: Train.o main.o
	g++ -g Train.o main.o -o lab1

Train.o: Train.cpp Train.hpp
	g++ -c -g Train.cpp -o Train.o 2> Train.log

main.o: main.cpp Train.hpp
	g++ -c -g main.cpp -o main.o 2> main.log

clean:
	rm -f *.o
	rm -f *.log
	rm -f lab1
