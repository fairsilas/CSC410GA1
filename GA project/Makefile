program: genome.o main.o population.o
	g++ -o program genome.o main.o
	
population.o: population.h population.cpp
	g++ -c population.cpp

genome.o: genome.h genome.cpp
	g++ -c genome.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o program
