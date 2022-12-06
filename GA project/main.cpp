#include "genome.cpp"   // this is assuming that the file has the same name as the
#include "population.cpp"
// class.
#include <iostream>   // this is so that the << redirect operators and 
                      // cout works
using namespace std;  // we use this so that we do not have to have 
                      // "std:" before cout and endl





int main() {
    srand(time(0));
    genome myGenome;
    population myPopulation;
    Pixel pixelTarget = { 100,100,100 };
    /*
    myGenome.set_mRate(0.5);
    myGenome.allocate(4); //allocates an array of 4 pixels in myGenome
    myGenome.randomize();
    myGenome.set_pixel(2, pixelTarget);
    myGenome.print();
    myGenome.calculate_overall_fitness(pixelTarget, 4);
    */

    myPopulation.generate_population(5, 5);
    myPopulation.print_population();
    myPopulation.set_target(pixelTarget, 25);
    cout << "Overall fitness: " << myPopulation.calculate_overall_fitness() << "\n";
    myPopulation.fselect_parents();
    myPopulation.print_parents();
    myPopulation.setn_nCrossover(1);
    myPopulation.set_mutation_rate(0.5);
    myPopulation.generate_new_population();
    myPopulation.print_population();
}
