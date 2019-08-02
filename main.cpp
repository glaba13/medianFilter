#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct pixel {
    unsigned int r;
    unsigned int g;
    unsigned int b;
};
int main(int argCount, char* argValue[])
{
    //Checking the expect number of parameters
    if (argCount < 2)
    {
        cout << "No Parameter";
        return -1;
    }

    //Initializing input and output files
    fstream ifile(argValue[1], ios_base::in | ios_base::binary);
    if (!ifile.is_open())
    {
        cout << "Error opening input file\n";
        return -1;
    }
    fstream ofile("outputfile.bmp", ios_base::out | ios_base::binary);
    if (!ofile.is_open())
    {
        cout << "Error creating output file\n";
        return -1;
    }

    //Reading the main header (always 14 bytes)
    unsigned char headerData[14];
    ifile.seekg(0);
    ifile.read((char*)headerData,14);
    unsigned int fileSize = *(int*)&headerData[2];
    unsigned int offset = *(int*)&headerData[10];

    //Reading image header (only the first twelve bytes -- header size, image width and image height)
    unsigned char imageheaderData[12];
    ifile.read((char*)imageheaderData,12);
    unsigned int width = *(int*)&imageheaderData[4];
    unsigned int height = *(int*)&imageheaderData[8];

    //Validating the main header against image header information
    unsigned int pixelDataSize = fileSize - offset;
    if (pixelDataSize != width*height*3)
    {
        cout << "This file is not a 24bit Bitmap file\n";
        return -1;
    }
    //Reading input data into two sections: pixel and non-pixel related data
    unsigned char* nonPixelData = new unsigned char[offset];
    ifile.seekg(0);
    ifile.read((char*)nonPixelData,offset);
    unsigned char* pixelData = new unsigned char[pixelDataSize];
    ifile.read((char*)pixelData,pixelDataSize);
    ifile.close();

    //Applying filter to the data.
    //In this example no filter is applied instead, a red border is drawn).
    //Remove/change the code below in order to apply the required filter
    //Indices are distributed from the lower left to the upper right corner
    unsigned int rowSize = width*3;
    unsigned int jCount = pixelDataSize / rowSize;
    unsigned int iCount = pixelDataSize / jCount;
    for(unsigned int j =0; j<jCount-2;j++)
    {
        for(unsigned int i =0; i<iCount - 6;i+=3)
        {
            vector<int> r;
            vector<int> g;
            vector<int> b;
            unsigned int index = (j + 1)*iCount + i + 3;
            for(unsigned int k1 =0; k1<3;k1++){
                for(unsigned int k2 =0; k2<3;k2++){
                    unsigned int inx= (j + k1)*iCount + i + 3*k2;
                    r.push_back(pixelData[inx]);
                    g.push_back( pixelData[inx+1]);
                    b.push_back(pixelData[inx+2]);
                }
            }
            sort(r.begin(), r.end());
            sort(g.begin(), g.end());
            sort(b.begin(), b.end());
            pixelData[index] = r[4];
            pixelData[index+1] = g[4];
            pixelData[index+2] = b[4];
        }
    }

    //Writing both sections into the output file
    ofile.seekg(0);
    ofile.write((char*)nonPixelData,offset);
    ofile.write((char*)pixelData,pixelDataSize);
    ofile.close();

    //Releasing remaining allocated resources
    delete[] nonPixelData;
    delete[] pixelData;

    return 0;
}