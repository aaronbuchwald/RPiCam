#include <string.h>
#include <string>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <chrono>
#include <csignal>
#include <thread>
#include <unistd.h>

// using namespace std::chrono;
namespace {
    volatile std::sig_atomic_t last_success = -1;
}

// writes data to the register at (0x70) and sets wiringPi pins to designate the correct camera
// return cam number changed to on success
// returns -1 for an illegal argument
int set_camera(iic_address, int cam) {
    int PIN7 = 7;
    int PIN11 = 0;
    int PIN12 = 1;

    if (cam == 1) {
        wiringPiI2CWriteReg8(iic_address, (0x00), 0x01);

        digitalWrite(PIN7, LOW);
        digitalWrite(PIN11, LOW);
        digitalWrite(PIN12, HIGH);

    } else if (cam == 2) {
        wiringPiI2CWriteReg8(iic_address, (0x00), 0x02);

        digitalWrite(PIN7, HIGH);
        digitalWrite(PIN11, LOW);
        digitalWrite(PIN12, HIGH);

    } else if (cam == 3) {
        wiringPiI2CWriteReg8(iic_address, (0x00), 0x04);

        digitalWrite(PIN7, LOW);
        digitalWrite(PIN11, HIGH);
        digitalWrite(PIN12, LOW);

    } else if (cam == 4) {
        wiringPiI2CWriteReg8(iic_address, (0x00), 0x08);
        
        digitalWrite(PIN7, HIGH);
        digitalWrite(PIN11, HIGH);
        digitalWrite(PIN12, LOW);
    } else {
        return -1;
    }

    return cam;
}


// takes picture and gives it the name of the argument with .jpg appended
std::string capture(std::string name) {
    std::string cmd ("raspistill -t 5 -ex sports --nopreview -o ");
    std::string command;
    command = cmd + name;

    // find correct c++ native function to do this to optimize
    // convert string to char* for system command
    char cmd_char[command.size() + 1];
    for (unsigned int i = 0 ; i < command.size() ; i++) {
        cmd_char[i] = command.at(i);
    }
    cmd_char[command.size()] = '\0';

    system(cmd_char);

    return command;
}

std::string num_as_string(int num) {
    if (num == 1) {
        return "1";
    } else if (num == 2) {
        return "2";
    } else if (num == 3) {
        return "3";
    } else if (num == 4) {
        return "4";
    } else if (num == 5) {
        return "5";
    } else if (num == 6) {
        return "6";
    } else {
        return "INVALID_NUMBER";
    }
}

// finds the difference between t1 and the current time and updates the time parameter to now
double find_time(std::chrono::high_resolution_clock::time_point &t1) {
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    double time_span_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1).count();
    t1 = std::chrono::high_resolution_clock::now();
    return time_span_seconds;
}

int test_cameras() {
    camera cam;

    set_camera(1);
    capture("cam1.jpg");

    set_camera(2);
    capture("cam2.jpg");

    set_camera(3);
    capture("cam3.jpg");

    set_camera(4);
    capture("cam4.jpg");

    return 0;
}

void sig_timeout_handler(int signal) {
    std::cout << "Camera timed out, trying again..." << std::endl;
}


void set_and_capture(camera cam, int camNum, std::string name) {
    set_camera(camNum);
    capture(name);

    last_success = 1;
}

int setupIIC() {
    std::cout << "Initializing the camera..." << std::endl;

    // wiringPi abstracts the physical pin numbers
    // pin number counterparts documented here: https://hackage.haskell.org/package/wiringPi
    // Assign the wiringPi pin numbers to the variables named for their physical pin numbering
    
    // sets up wiringPi must be called before using pins
    int iic_address = wiringPiI2CSetup((0x70));
    if (iic_address < 0) {
	    throw "IIC Setup failed";
    }
    else {
	    int write = wiringPiI2CWriteReg8(iic_address, (0x00), (0x01));
	    if (write < 0) {
	        throw "Write failed";
	    }
    }

    return iic_address;
}

int setupGPIO() {
    wiringPiSetup();
    
    // makes sure to initialize these correctly as the wiringPi versions of the physical numbers
    int PIN7 = 7;
    int PIN11 = 0;
    int PIN12 = 1;


    // sets the pins to output mode
    pinMode(PIN7, OUTPUT);
    pinMode(PIN11, OUTPUT);
    pinMode(PIN12, OUTPUT);

    return 1;
}


void cap_sequence_with_timeout() {
    // Creates the timeout handler
    std::signal(SIGUSR1, sig_timeout_handler);

    int iic_address = setupIIC();

    int gpioSetup = setupGPIO();

    // std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    // double time_difference = 0.0;

    for (int round = 1; round <= 6 ; round++) {
        for (int camNum = 1; camNum <= 3; camNum++) {
            last_success = 0;
            std::thread thread_capture(&set_and_capture, camNum, "dummy");
            thread_capture.detach();
            
            usleep(2000000);
            if (last_success != 1) {
                camNum -= 1;
                raise(SIGUSR1);
            } else {
                // Pass through as this indicates that the last picture was taken successfully
            }
        }
    }
}

int main() {
    //test_cameras();
    // need to initialize I2C first before usage, this should all be done in the constructor of the camera object
    cap_sequence_with_timeout()

    return 1;
}


