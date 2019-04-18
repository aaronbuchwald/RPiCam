#ifndef _CAPTURE_SEQUENCE_H
#define _CAPTURE_SEQUENCE_H

#include "IIC.h"
#include "camera.h"
#include <string.h>

int set_camera(int cam);
std::string capture(std::string name);

#endif