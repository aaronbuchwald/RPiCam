#include "IIC.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;


int ePin = 7;
int f1Pin = 11;
int f2Pin = 12;

// initializes the i2c for this device and initializes the camera component
// must restart the RPi after initializing for the RPiCam to work
void init() {
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
    system("raspistill -o image.jpg");

    return name;
}


void read_pins() {
    cout << digitalRead(7) << endl;
    cout << digitalRead(11) << endl;
    cout << digitalRead(12) << endl;
}

int main() {
    system("vcgencmd get_camera > /tmp/get_camera.txt");
    string line;
    bool camera_supported = false;
    bool camera_detected = false;
    ifstream file ("/tmp/get_camera.txt");
    if (file.is_open()) {
	if (getline(file, line) ) {
	    cout << line.at(10) << line.at(21) << endl;
	    if (line.at(10) == '1') {
		camera_supported = true;
		cout << "Camera is supported." << endl;
	    } else {
		cout << "Camera is not currently supported." << endl;
	    }
	    if (line.at(21) == '1') {
		camera_detected = true;
		cout << "Camera is detected." << endl;
	    } else {
		cout << "Camera is not detected." << endl;
	    }
	}
	file.close();
    } else {
	cout << "Unable to open the file" << endl;
    }


    if (camera_supported && camera_detected) {
	cout << "Camera has already been initialized." << endl;
    } else {
	init();
	// system("sudo reboot");
    }

    return 0;
}

