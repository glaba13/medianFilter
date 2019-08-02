//
// Created by Guri on 01/08/2019.
//

#ifndef MEDIAN_IMAGE_H
#define MEDIAN_IMAGE_H


#include "Filter.h"

class Filter;
typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
}Pixel;

class Image {
public:
    Image(unsigned char * data,  unsigned int width,  unsigned int height);

    Image();

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    unsigned char * getData() const { return m_data; }
    void resize(unsigned int width, unsigned int height);
    void applyFilter(Filter &f);
    ~Image();

    unsigned int getTotalSize();

private:
    unsigned char * m_data;
    unsigned int m_width;
    unsigned int m_height;

};


#endif //MEDIAN_IMAGE_H
