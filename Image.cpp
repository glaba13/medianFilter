//
// Created by Guri on 01/08/2019.
//

#include "Image.h"
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Constuctor
 * @param data : image data
 * @param width  : width of img
 * @param height  : height of img
 */
Image::Image(unsigned char *data, unsigned int width, unsigned int height) :
        m_data(data), m_width(width), m_height(height) {

}

/**
 * Destructor
 */
Image::~Image() {
    if (!m_data) {
        delete[] m_data;
    }
}

/**
 * Resize function, to be implemented
 * @param width : destination width
 * @param height : destination height
 */
void Image::resize(unsigned int width, unsigned int height) {
    //TODO
}

/**
 * @return total size of img data
 */
unsigned int Image::getTotalSize() {
    return m_width * m_height * 3;
}

//Applying filter to the data and modify img
void Image::applyFilter(Filter &f) {
    unsigned int rowSize = m_width * 3;
    unsigned int pixelDataSize = m_width * m_height * 3;
    unsigned int jCount = pixelDataSize / rowSize;
    unsigned int iCount = pixelDataSize / jCount;
    auto *pixelDataNew = new unsigned char[pixelDataSize]; // new img
    for (int i = 0; i < pixelDataSize; i++)
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
    if (!m_data) delete[] m_data; // release the old one
    m_data = pixelDataNew;
}

/**
 * Empty constuctor
 */
Image::Image() : m_data(nullptr), m_width(0), m_height(0) {

}
