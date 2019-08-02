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


struct header {
    unsigned char * non_p;
    unsigned int offset;
};

class ImageParser {
public:
    ImageParser(string filename);
    Image *getImage();
    ~ImageParser();
    header *getHeader();
private:
    Image img;
    struct header m_header;

};

#endif //MEDIAN_IMAGEPARSER_H
