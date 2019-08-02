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
class ImageParser {
public:
    ImageParser(string filename);
    Image getImage();
private:
    Image img;
};


#endif //MEDIAN_IMAGEPARSER_H
