#include <iostream>
#include <unistdh.h>

#include <string>
#include <string.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>
//
// #define ENABLE_CAMERA_4 // Parameter to enable/disable camera 4
// #define TEST

int extraPins[4] =  {3, 4, 13, 6};


int setup() {
    wiringPiSetup();
    pinMode(7, OUTPUT);
    pinMode(0, OUTPUT);
    pinMOde(1, OUTPUT);
    
    digitalWrite(1, HIGH);
    digitalWrite(0, HIGH);


    for (int i = 0 ; i < extraPins.length ; i++ ) {
        pinMode(extraPins[i], OUTPUT);
        digitalWrite(extraPinsp[i], HIGH);
    }

    return 0;
}

// Set the camera utilizing i2c and GPIO interfaces
// 1-4 corresponds to Cameras A-D as labelled on multiplexer
int set_camera(int num) {
    if (cam == 1) {
        system("i2cset -y 1 0x70 0x00 0x04");
        digitalWrite(7, LOW);
        digitalWrite(0, LOW);
        digitalWrite(1, HIGH); // TODO see if doing this when pin 12 starts as low causes an error because then all are low at some point
    } else if (cam == 2) {
        system("i2cset -y 1 0x70 0x00 0x05");
        digitalWrite(7, HIGH);
        digitalWrite(0, LOW);
        digitalWrite(1, HIGH);
    } else if (cam == 3) {
        system("i2cset -y 1 0x70 0x00 0x05");
        digitalWrite(7, HIGH);
        digitalWrite(0, LOW);
        digitalWrite(1, HIGH);
    } else if (cam == 4) {
        #ifdef ENABLE_CAMERA_4
        system("i2cset -y 1 0x70 0x00 0x07");
        digitalWrite(7, HIGH);
        digitalWrite(0, HIGH);
        digitalWrite(1, LOW);
        #else
        return -4; // Indicates incorrect parameter 4
        #endif
    } else {
        return -5; // -5 indicates incorrect parameter, none of 1-4
    }
}

// Captures picture and names it name in current directory
std::string capture(std::string name) {
    std::string cmd ("raspistill -t 100 --nopreview -o ");
    std::string command;
    command = cmd + name;

    // find correct c++ native function to do this to optimize
    // convert string to char* for system command
    char cmd_char[command.size() + 1];
    for (unsigned int i = 0 ; i < command.size() ; i++) {
        cmd_char[i] = command.at(i);
    }
    cmd_char[command.size()] = '\0';
    std::cout << cmd_char << std::endl;
    system(cmd_char);

    return command;
}

void test_cameras() {
    setup();
    set_camera(1);
    capture("CAMERA_A.jpg");
    set_camera(2);
    capture("CAMERA_B.jpg");
    set_camera(3);
    capture("CAMERA_C.jpg");
    
    #ifdef ENABLE_CAMERA_4
    set_camera(4);
    capture("CAMERA_D.jpg");
    #endif
}

// Precodnition: setup must have already been run
int iteration(std::string base_name) {
    set_camera(1);
    capture(base_name + "_1.jpg");
    set_camera(2);
    capture(base_name + "_2.jpg");
    set_camera(3);
    capture(base_name + "_3.jpg");
    #ifdef ENABLE_CAMERA_4
    set_camera(4);
    capture(base_name + "_4.jpg");
    #endif

    return 0;
}

int capture_sequence() {
    iteration("round1");
    iteration("round2");
    iteration("round3");
    iteration("round4");
    iteration("round5");
    iteration("round6");

    return 0;
}

int main() {
    setup();

    #ifndef TEST
    capture_sequence();
    #else
    test_cameras();
    #endif
}
