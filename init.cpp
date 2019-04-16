#include "IIC.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>

using namespace std;


int ePin = 7;
int f1Pin = 11;
int f2Pin = 12;

// initializes the i2c for this device and initializes the camera component
// must restart the RPi after initializing for the RPiCam to work
void init() {
    wiringPiI2CSetup(1);
    IIC((0x70), (0x01));
}

void setup_pins() {
    pinMode(7, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

int set_camera(int cam) {
    if (cam == 1) {
        digitalWrite(7, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
    } else if (cam == 2) {
        digitalWrite(7, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);   
    } else if (cam == 3) {
        digitalWrite(7, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
    } else {
        return -1;
    }
    return 0;
}

string capture(string name) {
    set_camera(cam);
    system("raspistill -o " << name);
    return name;
}

int capture_sequence(int a, int b, int c) {
    string end = ".jpg";
    set_camera(a);
    capture(a << end);
    set_camera(b);
    capture(b << end);
    set_camera(c);
    capture(c << end);
}



void read_pins() {
    cout << digitalRead(7) << endl;
    cout << digitalRead(11) << endl;
    cout << digitalRead(12) << endl;
}

int main() {
    init();
    wiringPiSetupGpio();
    read_pins();
    set_camera(1);
    read_pins();
}

