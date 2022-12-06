#include "genome.cpp"   // this is assuming that the file has the same name as the
#include "population.cpp"
// class.
#include <iostream>   // this is so that the << redirect operators and 
                      // cout works
using namespace std;  // we use this so that we do not have to have 
                      // "std:" before cout and endl





int main() {
    srand(time(0));
    population myPopulation;
    Pixel pixelTarget = { 100,100,100 };
    
    
    

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


    //create a genome for testing
    genome testGenome;
    testGenome.set_mRate(0.5);
    testGenome.allocate(8); //allocates an array of 2 pixels
    testGenome.set_pixel(0, {100,100,100}); // set both pixels to {100,100,100}
    testGenome.set_pixel(0, { 100,100,100 });
    

    //if the test fails show the line where the test failed otherwise print nothing
    #define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }
 
    ///test functions for GA2 Genome class

    //test get_mRate() method
    IS_TRUE(testGenome.get_mRate() == 0.5); // make sure returns correct mrate 
    IS_TRUE(testGenome.get_mRate() != 100); // check to make sure mrate not equal to any other number

    //test calculate_gene_fitness(int index, Pixel targetPixel) method
    IS_TRUE(testGenome.calculate_gene_fitness(0, { 200,200,200 }) < 1); // fitness should be number not be <1


    //test double calculate_overall_fitness(Pixel target, int nPixels) 
    IS_TRUE(testGenome.calculate_overall_fitness({ 200,200,200 }, 8) > 0); // fitness should be number <1
    // 
    // 
    //test int get_nGenes()
    IS_TRUE(testGenome.get_nGenes() == 8); // should have 8 genes
    IS_TRUE(testGenome.get_nGenes() != -2); // should not have - genes
    IS_TRUE(testGenome.get_nGenes() != 10000); // created with 8 genes should not have 10000



}

