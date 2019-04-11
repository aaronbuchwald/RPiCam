#include "IIC.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>


int main() {
    int init_output = init();

    return init_output;
}

int init() {
    wiringPiI2CSetup(1);
    int fd = wiringPiI2CSetup((0x70));
    int output = wiringPiI2CWriteReg8(fd, (0x00), (0x01));
}

int init1() {
    wiringPiI2CSetup(1);
    IIC iviic = IIC((0x70), (0x01));
}

int change_camera(int cam) {

}