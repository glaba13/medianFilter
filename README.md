# Simple Median Filter

The program applies the median filter to the image

**Note**: the exe file is located in __release_exe__ folder

The command general structure is:
```sh
$ ./Median  path/to/file_name [-k[N]]
```

As it can be seen it takes a file as a main argument and optional flag:

  - **-k[N]** :factor of median filter. _example: -k5_ [default k = 3]


![Architecture_struct](https://raw.githubusercontent.com/glaba13/ImageResources/master/arch4.PNG)

The design consist of:

- **Image parser**: which parse the file and deserializes it into image class
- **Image builder**: builds output file depending on the new image
- **Image class**: contains image information
- **Abstract filter class**, which is generally for convolutional filters
- **Median filter class** is the specific implementation of abstract filter class




## Specification
The solution is implemented with C++ and using Clion IDE on Windows
Using MingGW-w64 version 5.0 toolchain.
CMakeList is included.

##Outputs
![Med](https://raw.githubusercontent.com/glaba13/ImageResources/master/med.png)

