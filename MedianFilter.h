//
// Created by Guri on 02/08/2019.
//

#ifndef MEDIAN_MEDIANFILTER_H
#define MEDIAN_MEDIANFILTER_H


#include "Filter.h"

class MedianFilter : public Filter {
public:
    /**
     * Constuctor of median filer
     * @param factor : k factor of the filer
     */
    MedianFilter(unsigned int factor = 3);

/**
 * Getter of the factor value
 * @return  k factor
 */
    unsigned int getFactor() const { return m_factor; }

/**
 * Applies filter for the window of kxk and retuns the cneter pixel value
 * @param im : image input
 * @param i : index of column
 * @param j : index of row
 * @return : rgb pixel value
 */
    struct Pixel apply(Image *im, unsigned int i, unsigned int j) override;

private:
    //private variable
    unsigned int m_factor;

};


#endif //MEDIAN_MEDIANFILTER_H
