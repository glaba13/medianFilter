//
// Created by Guri on 01/08/2019.
//

#ifndef MEDIAN_IMAGEBUILDER_H
#define MEDIAN_IMAGEBUILDER_H

#include <string>
#include <fstream>
#include "Image.h"

using namespace std;

class ImageBuilder {
    public:
    ImageBuilder(string filename);

    void writeImage(Image im);

private:
    fstream ofile;

};


#endif //MEDIAN_IMAGEBUILDER_H
