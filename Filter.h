//
// Created by Guri on 02/08/2019.
//

#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H


#include "Image.h"

class Image;

class Filter {
public:
    Filter(unsigned int m, unsigned int n);

    /**
     * @return  m dimention
     */
    unsigned int getM() const { return m_m; }

/**
 * @return N dimention 
 */
    unsigned int getN() const { return m_n; }

/**
 * Virtual filter function
 * @param im  image 
 * @param i column index postion
 * @param j row index position
 * @return Modified center pixel value
 */
    virtual struct Pixel apply(Image *im, unsigned int i, unsigned int j) = 0;

private:
    // private variables
    unsigned int m_m;
    unsigned int m_n;
};


#endif //MEDIAN_FILTER_H
