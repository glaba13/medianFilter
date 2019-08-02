//
// Created by Guri on 02/08/2019.
//

#include "MedianFilter.h"
#include <vector>
#include <algorithm>
using namespace std;
MedianFilter::MedianFilter(unsigned int factor) : Filter(factor,factor){
    m_factor = factor;
}

Pixel MedianFilter::apply(Image *im, unsigned int i, unsigned int j) {
    vector<int> r;
    vector<int> g;
    vector<int> b;
    unsigned  int iCount = im->getWidth()*3;
    unsigned char * data = im->getData();
    for (unsigned int k1 = 0; k1 < m_factor; k1++) {
        for (unsigned int k2 = 0; k2 < m_factor; k2++) {
            unsigned int inx = (j + k1) * iCount + i + 3 * k2;

            r.push_back(data[inx]);
            g.push_back(data[inx + 1]);
            b.push_back(data[inx + 2]);
        }
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    unsigned int med_indx = (m_factor * m_factor) / 2;
    Pixel p;
    p.r = r[med_indx];
    p.g = g[med_indx];
    p.b = b[med_indx];
    return p;
}