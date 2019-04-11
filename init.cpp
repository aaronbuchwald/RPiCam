#include "IIC.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>


int ePin = 7;
int f1Pin = 11;
int f2Pin = 12;

// initializes the i2c for this device and initializes the camera component
// must restart the RPi after initializing for the RPiCam to work
void init() {
    wiringPiI2CSetup(1);
    IIC iviic = IIC((0x70), (0x01));
}

void setup_pins() {
    pinMode(7, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

int set_camera(int cam) {
    if (cam == 1) {
        digitalWrite(7, 0);
        digitalWrite(11, 0);
        digitalWrite(12, 1);
    } else if (cam == 2) {
        digitalWrite(7, 0);
        digitalWrite(11, 1);
        digitalWrite(12, 1);   
    } else if (cam == 3) {
        digitalWrite(7, 1);
        digitalWrite(11, 0);
        digitalWrite(12, 0);
    } else {
        // throw error
    }
}


int main() {
    return init();
}

