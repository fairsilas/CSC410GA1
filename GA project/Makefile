program: genome.o main.o
	g++ -o program genome.o main.o

genome.o: genome.h genome.cpp
	g++ -c genome.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o program
