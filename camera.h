#ifndef _IIC_H
#define _IIC_H

#include <string.h>
#include <string>
#include "IIC.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <iostream>


class camera {
    public:
        int set_camera(int);
        std::string capture(std::string name);
    private:
        IIC iviic;
        int PIN7, PIN11, PIN12;
};

#endif