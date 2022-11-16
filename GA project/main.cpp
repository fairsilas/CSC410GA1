#include "genome.cpp"   // this is assuming that the file has the same name as the
// class.
#include <iostream>   // this is so that the << redirect operators and 
                      // cout works
using namespace std;  // we use this so that we do not have to have 
                      // "std:" before cout and endl


int main() {
    genome myGenome;
    myGenome.set_mRate(0.5);
    myGenome.allocate(4); //allocates an array of 4 pixels in myGenome
    myGenome.randomize();
    myGenome.print();
    myGenome.set_pixel(2,{100,100,100});
    myGenome.print();
    myGenome.calculate_overall_fitness({ 100,100,100 }, 4);
    return 0;
}
