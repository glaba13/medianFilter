//
// Created by Guri on 01/08/2019.
//

#ifndef MEDIAN_IMAGEPARSER_H
#define MEDIAN_IMAGEPARSER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Image.h"

using namespace std;

/**
 * Helper struct for header [should be avoided]
 */
struct header {
    unsigned char *non_p;
    unsigned int offset;
};

class ImageParser {
public:
    /**
     * Constuctor
     * @param filename : input filename
     */
    ImageParser(string filename);

/**
 * Returnes the parsed image
 * @return image
 */
    Image *getImage();

    ~ImageParser();

/**
 * Getter of header info
 * @return header
 */
    header *getHeader();

private:
    //Private members
    Image img;
    struct header m_header;

};

#endif //MEDIAN_IMAGEPARSER_H
