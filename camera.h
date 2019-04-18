#ifndef _CAMERA_H
#define _CAMERA_H

#include <string.h>
#include <string>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "IIC.h"
#include <stdlib.h>
#include <iostream>


class camera {
    public:
        camera();
        int set_camera(int);
        std::string capture(std::string name);
    private:
        IIC iviic;
        int PIN7, PIN11, PIN12;
};

#endif