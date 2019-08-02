//
// Created by Guri on 01/08/2019.
//

#include "ImageBuilder.h"
#include <string>
#include <iostream>
#include "Image.h"
#include "ImageParser.h"

/**
 * Output image file builder with filename
 * @param filename
 */
ImageBuilder::ImageBuilder(string filename) {
    ofile = fstream(filename, ios_base::out | ios_base::binary);
    if (!ofile.is_open()) {
        throw std::runtime_error("Could not open output file");
    }
}

/**
 * Write the image into file
 * @param im  image data
 * @param h  header (should be avoided)
 */
void ImageBuilder::writeImage(Image *im, struct header *h) {
    //Writing both sections into the output file
    ofile.seekg(0);
    if (h) {
        ofile.write((char *) h->non_p, h->offset);
    }
    ofile.write((char *) im->getData(), im->getTotalSize());
    ofile.close();
}
