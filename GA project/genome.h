// what the class does

#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

class Pixel {
public:
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
    void print()
    {
        for (int i = 0; i < nGenes; i++)
        {
            cout << "gene " << i << "(" << get_red(i) << ", " << get_green(i) << ", " << get_blue(i) << ")\n";
        }
    }

    Pixel* genes;
    int nGenes;
private:

};

