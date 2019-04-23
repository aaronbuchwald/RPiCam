#ifndef _CAMERA1_H
#define _CAMERA1_H

#include <string.h>
#include <string>
// #include <wiringPi.h>
// #include <wiringPiI2C.h>
// #include "IIC.h"
#include <stdlib.h>
#include <iostream>


class camera {
    public:
        camera(int mode);
        int set_camera(int cam_num);
        std::string capture(std::string name);
    private:
        int PIN7, PIN11, PIN12;
};

#endif