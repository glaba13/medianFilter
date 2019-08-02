//
// Created by Guri on 02/08/2019.
//

#ifndef MEDIAN_MEDIANFILTER_H
#define MEDIAN_MEDIANFILTER_H


#include "Filter.h"

class MedianFilter : public Filter{
public:
    MedianFilter(unsigned int factor = 3);
    unsigned int getFactor() const { return m_factor;}
    struct Pixel apply(Image *im, unsigned int i, unsigned int j) override;
private:
    unsigned int m_factor;

};


#endif //MEDIAN_MEDIANFILTER_H
