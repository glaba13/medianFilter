#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "ImageBuilder.h"
#include "ImageParser.h"

using namespace std;
#define K_AVG          "-k"

void process_k_option(string arg, int &k);

int main(int argCount, char *argValue[]) {
    //Checking the expect number of parameters
    if (argCount < 2) {
        cout << "No Parameter";
        return -1;
    }

    int factor = 3;
    for (int i = 1; i < argCount; ++i) {
        string arg = string(argValue[i]);
        if (arg.find(K_AVG) == 0) {
            process_k_option(arg, factor);
        }
    }

    ImageParser ip((string(argValue[1])));
    Image im = ip.getImage();
    Filter f;
    im.applyFilter(f);
    ImageBuilder ib("out.bmp");
    ib.writeImage(im);

    //Releasing remaining allocated resources
//    delete[] nonPixelData;
//    delete[] pixelData;
//    delete[] pixelDataNew;

    return 0;
}

void process_k_option(string arg, int  &k) {
    string num_str = arg.substr(string(K_AVG).size());
    if (num_str.size() > 0) {
        std::istringstream iss(num_str);
        unsigned long long num;
        iss >> num;
        if (!iss.fail()) {
            k = num;
        }
    }
}
