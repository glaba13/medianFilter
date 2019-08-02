//
// Created by Guri on 01/08/2019.
//

#ifndef MEDIAN_IMAGE_H
#define MEDIAN_IMAGE_H


#include "Filter.h"

class Filter;

/**
 * Pixel rgb struct
 */
typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

class Image {
public:
    /**
     * Constuctor
     * @param data : data values
     * @param width
     * @param height
     */
    Image(unsigned char *data, unsigned int width, unsigned int height);

    Image();

/**
 * Width getter
 * @return  width
 */
    int getWidth() const { return m_width; }

/**
 * Height getter
 * @return height
 */
    int getHeight() const { return m_height; }

/**
 * Data getter
 * @return data
 */
    unsigned char *getData() const { return m_data; }

/**
 * Resize function
 * @param width : to be resized
 * @param height : to be resized
 */
    void resize(unsigned int width, unsigned int height);

/**
 * Apply filter function as convolution
 * @param f  filter
 */
    void applyFilter(Filter &f);

/**
 * Destuctor
 */
    ~Image();

    unsigned int getTotalSize();

private:
    unsigned char *m_data;
    unsigned int m_width;
    unsigned int m_height;

};


#endif //MEDIAN_IMAGE_H
