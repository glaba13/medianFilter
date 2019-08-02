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
    /**
     * Constuctor
     * @param filename: output fil ename
     */
    ImageBuilder(string filename);

    /**
     * Image to be writen
     * @param im  image
     * @param h  header
     */
    void writeImage(Image *im, struct header *h = nullptr);

private:
    //private variables
    fstream ofile;

};


#endif //MEDIAN_IMAGEBUILDER_H
