#include <iostream>
#include <fstream>
#include <vector>

#include "ImageBuilder.h"
#include "ImageParser.h"
#include "MedianFilter.h"

using namespace std;

// argument flag for changing factor
#define K_AVG          "-k"
//default factor
#define DEFAULT_K      (3)

void process_k_option(string arg, unsigned int &k);

void process(char *string, unsigned int k);

int main(int argCount, char *argValue[]) {
    //Checking the expect number of parameters
    if (argCount < 2) {
        cout << "No Parameter";
        return -1;
    }

    //check for the factor change
    unsigned int factor = DEFAULT_K;
    for (int i = 1; i < argCount; ++i) {
        string arg = string(argValue[i]);
        if (arg.find(K_AVG) == 0) {
            process_k_option(arg, factor);
        }
    }
    //Process input and generate output
    try {
        process(argValue[1], factor);
    } catch (std::exception &ex) {
        std::cout << "Error occured: " << ex.what() << "!\n";
        return -1;
    }
    return 0;
}

/**
 * Parse file, applies filter and generates output
 * @param filename : input filename
 * @param factor  : factor of median filter
 */
void process(char *filename, unsigned int factor) {
    ImageParser ip((string(filename)));
    Image *im = ip.getImage();
    MedianFilter f(factor);
    im->applyFilter(f);
    ImageBuilder ib("out.bmp");
    ib.writeImage(im, ip.getHeader());
}

void process_k_option(string arg, unsigned int &k) {
    string num_str = arg.substr(string(K_AVG).size());
    if (num_str.size() > 0) {
        std::istringstream iss(num_str);
        unsigned int num;
        iss >> num;
        if (!iss.fail()) {
            k = num;
        }
    }
}
