#include <cstdlib>
#include "genome.cpp"
#include <random>
#include <iostream>
//# include <string>
#ifndef POPULATION_H
#define POPULATION_H
#include <time.h>



class population {
	public:
		//default constructor that initializes individuals to nulland nIndividuals to 0.
			//The number of crossover points should be set to 1.
			//destructor that deletes individuals if is it not NULL alreadyand sets it to NULLand nIndividuals to 0

		//constructor
		population() {
			genome* individuals = NULL;
			int nIndividuals = 0;
			parent1 = 0;
			parent2 = 0;

		}

		// destructor
		~population() {
			deallocate();
		}

		//dealocate individuals 
		void deallocate()
		{
			if ((individuals == NULL )&&( nIndividuals == 0)){
				return;
			}
			nIndividuals = 0;
			delete individuals;
		}

		//generate a population of genomes
		void generate_population(int popSize, int numGenes) {
			
			if (individuals != NULL) {
				deallocate();
				nIndividuals = 0;
			}

			nIndividuals = popSize;

			individuals = new genome[popSize];
			for (int i = 0; i < nIndividuals; i++) {
				individuals[i].allocate(numGenes);
				individuals[i].randomize();
			}
		}

		//return the target genome
		genome get_target() {
			return targetGenome;
		}
		
		
		//sets the target fitness image in the class 
		void set_target(Pixel target, int imageSize) {
			//targetGenome = target;
			targetGenome.allocate(imageSize);
			for (int i = 0; i < imageSize; i++)
				targetGenome.set_pixel(i, target);
		}
		
		//set crossover point
		void setn_nCrossover(int numCrossover) {
			nCrossover = numCrossover;
		}

		//return crossover number (should always be 1 for this)
		int get_nCrossover() {
			return nCrossover;
		}
			
		//select parent genes and copy them to genome variables parent1, parent 2
		void fselect_parents() {
			double p1_fitness  = 0;
			double p2_fitness = 0;
			for (int i = 0; i < nIndividuals; i++) {
				double fitness = individuals[i].calculate_overall_fitness(targetGenome.get_pixel(i), individuals[i].get_nGenes());
				
				if (p1_fitness < fitness) {
					p2_fitness = p1_fitness;
					p1_fitness = fitness;
					parent2 = parent1;
					parent1 = i;
				}
				else if (p2_fitness < fitness) {
					p2_fitness = fitness;
					parent2 = i;
				}
				
			}
			cout << "parent 1 fitness: " << p1_fitness << "\n";
			cout << "parent 2 fitness: " << p2_fitness << "\n";
		}

		//set mutation rate
		void set_mutation_rate(double mutation_rate) {
			mutationRate = mutation_rate;
		}

		//generate new popultion
		void generate_new_population(int use_Roulette = 0){
			if (use_Roulette == 0){
				for (int i = 0; i < nIndividuals; i++) {
					//get a random crossover point
					int crossover = (rand() % individuals[i].get_nGenes()+1) ;
					cout << "crossover = " << crossover << "\n";
					if ((i != parent1) && (i != parent2)) {
						for (int k = 0; k < crossover; k++) {
							individuals[i].set_pixel(k, individuals[parent1].get_pixel(k));
						}
						for (int k = 0; k <  nIndividuals-crossover; k++) {
							individuals[i].set_pixel(k+ crossover, individuals[parent2].get_pixel(k+ crossover));

						}
					}
				}
			}
			else {
				//extra credit: use roulette method
			}
		}

		

		//print out parent genomes
		void print_parents() {
			cout << "Parent 1 genome: ";
			individuals[parent1].print();
			cout << "Parent 2 genome: ";
			individuals[parent2].print();
		}
		
		

		//calculate overall fitness by comparing target genome to each individual
		double calculate_overall_fitness() {
			double avgFitness = 0;
			for (int i = 0; i < nIndividuals; i++) {
				avgFitness += individuals[i].calculate_overall_fitness(targetGenome.get_pixel(i), individuals[i].get_nGenes());
			}
			return avgFitness / nIndividuals;
		}

		//print the entire population
		void print_population() {
			for (int i = 0; i < nIndividuals; i++) {
				cout << " population" << i << " ";
				individuals[i].print();
			}

		}


	private:
		int nIndividuals = 0;
		genome* individuals = NULL;

		int nCrossover = 1;
		double mutationRate = 0.5;
		int parent1;
		int parent2;
		int ntargetGenome = 0;
		genome targetGenome;

};

#endif
