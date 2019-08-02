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

}


unsigned int Image::getTotalSize() {
    return m_width*m_height*3;
}

void Image::applyFilter(Filter f) {

    //Applying filter to the data.
    //In this example no filter is applied instead, a red border is drawn).
    //Remove/change the code below in order to apply the required filter
    //Indices are distributed from the lower left to the upper right corner
    unsigned int rowSize = m_width * 3;
    unsigned int pixelDataSize = m_width * m_height*3;
    unsigned int jCount = pixelDataSize / rowSize;
    unsigned int iCount = pixelDataSize / jCount;
    unsigned char *pixelDataNew = new unsigned char[pixelDataSize];
    for (int i = 0; i < pixelDataSize; i ++)
         pixelDataNew[i] = m_data[i];
    int factor = 3;
    for (unsigned int j = 0; j < jCount - (factor - 1); j++) {
        for (unsigned int i = 0; i < iCount - (factor - 1) * 3; i += 3) {
            vector<int> r;
            vector<int> g;
            vector<int> b;
            unsigned int index = (j + factor / 2) * iCount + i + (factor / 2) * 3;
            for (unsigned int k1 = 0; k1 < factor; k1++) {
                for (unsigned int k2 = 0; k2 < factor; k2++) {
                    unsigned int inx = (j + k1) * iCount + i + 3 * k2;
                    r.push_back(m_data[inx]);
                    g.push_back(m_data[inx + 1]);
                    b.push_back(m_data[inx + 2]);
                }
            }
            sort(r.begin(), r.end());
            sort(g.begin(), g.end());
            sort(b.begin(), b.end());
            int med_indx = (factor * factor) / 2;
            pixelDataNew[index] = r[med_indx];
            pixelDataNew[index + 1] = g[med_indx];
            pixelDataNew[index + 2] = b[med_indx];
        }
    }
    if(!m_data) delete [] m_data;
    m_data = pixelDataNew;
}

Image::Image() : m_data(nullptr), m_width(0), m_height(0) {

}
