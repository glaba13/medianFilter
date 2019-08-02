//
// Created by Guri on 01/08/2019.
//

#include "ImageParser.h"

ImageParser::ImageParser(string filename) {
    fstream ifile(filename, ios_base::in | ios_base::binary);
    if (!ifile.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    //Reading the main header (always 14 bytes)
    unsigned char headerData[14];
    ifile.seekg(0);
    ifile.read((char *) headerData, 14);
    unsigned int fileSize = *(int *) &headerData[2];
    unsigned int offset = *(int *) &headerData[10];

    //Reading image header (only the first twelve bytes -- header size, image width and image height)
    unsigned char imageheaderData[12];
    ifile.read((char *) imageheaderData, 12);
    unsigned int width = *(int *) &imageheaderData[4];
    unsigned int height = *(int *) &imageheaderData[8];

    //Validating the main header against image header information
    unsigned int pixelDataSize = fileSize - offset;
    if (pixelDataSize != width * height * 3) {
        throw std::runtime_error("This file is not a 24bit Bitmap file");
    }
    //Reading input data into two sections: pixel and non-pixel related data
    unsigned char *nonPixelData = new unsigned char[offset];
    ifile.seekg(0);
    ifile.read((char *) nonPixelData, offset);
    unsigned char *pixelData = new unsigned char[pixelDataSize];
  //
    ifile.read((char *) pixelData, pixelDataSize);

    ifile.close();
    img = Image(pixelData, width, height);
    img.non_p = nonPixelData;
    img.offset = offset;
}

Image ImageParser::getImage() {
    return img;
}
