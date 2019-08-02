//
// Created by Guri on 01/08/2019.
//

#include "ImageBuilder.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Image.h"

ImageBuilder::ImageBuilder(string filename) {


    ofile = fstream(filename, ios_base::out | ios_base::binary);
    if (!ofile.is_open()) {
        throw std::runtime_error("Could not open output file");
    }


    //Initializing input and output files

}

void ImageBuilder::writeImage(Image im) {

    //Writing both sections into the output file
    ofile.seekg(0);
    ofile.write((char *) im.non_p, im.offset);
    ofile.write((char *) im.getData(), im.getTotalSize());
    ofile.close();

}
