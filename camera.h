#ifndef _CAMERA_H
#define _CAMERA_H

#include <string.h>
#include <string>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "IIC.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>

// add in the extra functions to camera for the capture sequence

class camera {
    public:
        camera();
        int set_camera(int);
        std::string capture(std::string name);
    private:
        int PIN7, PIN11, PIN12;
        IIC iviic;
};

#endif