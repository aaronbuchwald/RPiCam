#ifndef _IIC_H
#define _IIC_H

#include "IIC.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

int set_camera(int cam);
std::string capture(std::string name);

#endif