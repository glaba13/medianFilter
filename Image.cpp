//
// Created by Guri on 01/08/2019.
//

#include "Image.h"
#include <vector>
#include <algorithm>
using namespace std;
Image::Image(unsigned char *data, unsigned int width, unsigned int height) :
    m_data(data), m_width(width), m_height(height)
{

}


Image::~Image() {
    if(!m_data) {
        delete [] m_data;
    }
}

void Image::resize(unsigned int width, unsigned int height) {
    //TODO
}


unsigned int Image::getTotalSize() {
    return m_width*m_height*3;
}

void Image::applyFilter(Filter &f) {

    //Applying filter to the data.
    //In this example no filter is applied instead, a red border is drawn).
    //Remove/change the code below in order to apply the required filter
    //Indices are distributed from the lower left to the upper right corner
    unsigned int rowSize = m_width * 3;
    unsigned int pixelDataSize = m_width * m_height*3;
    unsigned int jCount = pixelDataSize / rowSize;
    unsigned int iCount = pixelDataSize / jCount;
    auto *pixelDataNew = new unsigned char[pixelDataSize];
    for (int i = 0; i < pixelDataSize; i ++)
         pixelDataNew[i] = m_data[i];
    unsigned int factor_m = f.getM();
    unsigned int factor_n = f.getN();

    for (unsigned int j = 0; j < jCount - (factor_m - 1); j++) {
        for (unsigned int i = 0; i < iCount - (factor_n - 1) * 3; i += 3) {

            unsigned int index = (j + factor_m / 2) * iCount + i + (factor_n / 2) * 3;
            Pixel p = f.apply(this, i, j);
            pixelDataNew[index] = p.r;
            pixelDataNew[index + 1] = p.g;
            pixelDataNew[index + 2] = p.b;
        }
    }
    if(!m_data) delete [] m_data;
    m_data = pixelDataNew;
}

Image::Image() : m_data(nullptr), m_width(0), m_height(0) {

}
