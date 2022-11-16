// what the class does

#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

struct Pixel {
    int red;
    int blue;
    int green;
};

class genome {
public:
    genome() {
        genes = NULL;
        nGenes = 0;
    }
    // constructor
    ~genome()
    {
        deallocate();
    }
    // destructor
    void allocate(int numGenes)
    {
        if (nGenes != NULL) {
            deallocate();
        }
        genes = new Pixel[numGenes];
        nGenes = numGenes;
    }
    //set mutation rate
    void set_mRate(double val) {
        if (val >= 0 && val <= 1) {
            mRate = val;
        }

    }

    //return the mutation rate
    double get_mRate() {
        return mRate;
    }

    // mutate a single gene
    void mutate_gene(int index) 
    {
        double min = 0;
        double max = 1;
        // if random 0-1 is less than mutation rate then set colors to random
        //mutate red
        double random = (double)rand() / 1;
        random = min + random * (max - min);
        if (random < mRate)
        {
            int redValue = (rand() % 226) + 1;
            set_red(index, redValue);
        }
        //mutate green
        random = (double)rand() / 1;
        random = min + random * (max - min);
        if (random < mRate)
        {
            int greenValue = (rand() % 226) + 1;
            set_green(index, greenValue);
        }
        //mutate blue
        random = (double)rand() / 1;
        random = min + random * (max - min);
        if (random < mRate)
        {
            int blueValue = (rand() % 226) + 1;
            set_blue(index, blueValue);
        }
    }

    // mutate the all genes
    void mutate() {
        for (int i = 0; i < nGenes; i++) {
            mutate_gene(i);
        }
    }

    // calculate gene fitness 
    double calculate_gene_fitness(int index, Pixel targetPixel) {
        float percent_red_error = abs(get_red(index) - targetPixel.red)/ double(226);
        double percent_green_error = abs(get_green(index) - targetPixel.green) / double(226);
        double percent_blue_error = abs(get_blue(index) - targetPixel.blue) / double(226);
        double gene_fitness = (percent_red_error + percent_green_error + percent_blue_error) / double(3);
        return gene_fitness;
    }

    //calculate overall fitness
    double calculate_overall_fitness(Pixel target, int nPixels) {
        double fitness_total = 0;
        for (int i = 0; i < nPixels; i++) {
            fitness_total += calculate_gene_fitness(i, target);
        }
        fitness_total /= nPixels;
        return fitness_total;
    }

    //set pixel
    void set_pixel(int index, Pixel newPixel) {
        if ((index <= nGenes) && (index >= 0)) {
            genes[index] = newPixel;
        }
        else {
            cout << "Out of range line 108-110 is bad";
        }
        
        
    }
    
    void deallocate()
    {
        if (genes == NULL)
        {
            return;
        }
        delete genes;
    }
    void randomize()
    {
        // value for rand is 227 because it starts at 0 to 226
        for (int i = 0; i < nGenes; i++)
        {

            int redValue = (rand() % 226) + 1;
            int greenValue = (rand() % 226) + 1;
            int blueValue = (rand() % 226) + 1;

            set_red(i, redValue);
            set_green(i, greenValue);
            set_blue(i, blueValue);
        }
    };
    void set_red(int index, int value)
    {
        genes[index].red = value;
    }
    int& get_red(int index)
    {
        return genes[index].red;
    }
    void set_green(int index, int value)
    {
        genes[index].green = value;
    }
    int& get_green(int index)
    {
        return genes[index].green;
    }
    void set_blue(int index, int value)
    {
        genes[index].blue = value;
    }
    int &get_blue(int index)
    {
        return genes[index].blue;
    }

    //print out all the genes color values
    void print() 
    {
        for (int i = 0; i < nGenes; i++)
        {
            cout << "gene " << i << "(" << get_red(i) << ", " << get_green(i) << ", " << get_blue(i) << ")\n";
        }
    }

    Pixel* genes;
    int nGenes;
    double mRate = 0;
private:

};

