program: genome.o main.o
	g++ -o program genome.o population.o main.o

genome.o: genome.h genome.cpp
	g++ -c genome.cpp

population.o: population.h population.cpp
	g++ -c population.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o program
