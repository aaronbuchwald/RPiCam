#ifndef _IIC_H
#define _IIC_H

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "IIC.h"
#include <iostream>
#include <string>

int set_camera(int cam);
std::string capture(std::string name);

#endif