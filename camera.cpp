#include "camera.h"


camera::camera() {
    std::cout << "Initializing the camera..." << std::endl;

    // wiringPi abstracts the physical pin numbers
    // pin number counterparts documented here: https://hackage.haskell.org/package/wiringPi
    // Assign the wiringPi pin numbers to the variables named for their physical pin numbering
    
    // sets up wiringPi must be called before using pins

    iviic = IIC((0x70), (0x01));

    wiringPiSetup();
    
    // makes sure to initialize these correctly as the wiringPi versions of the physical numbers
    PIN7 = 7;
    PIN11 = 0;
    PIN12 = 1;


    // sets the pins to output mode
    pinMode(PIN7, OUTPUT);
    pinMode(PIN11, OUTPUT);
    pinMode(PIN12, OUTPUT);
}

// writes data to the register at (0x70) and sets wiringPi pins to designate the correct camera
// return cam number changed to on success
// returns -1 for an illegal argument
int camera::set_camera(int cam) {
    pinMode(PIN7, OUTPUT);
    pinMode(PIN11, OUTPUT);
    pinMode(PIN12, OUTPUT);


    if (cam == 1) {
        // wiringPiI2CWriteReg8((0x70), (0x00), (0x01));
        iviic.write_control_register(0x01);

        digitalWrite(PIN7, LOW);
        digitalWrite(PIN11, LOW);
        digitalWrite(PIN12, HIGH);

    } else if (cam == 2) {
        // wiringPiI2CWriteReg8((0x70), (0x00), (0x02));
        iviic.write_control_register(0x02);

        digitalWrite(PIN7, HIGH);
        digitalWrite(PIN11, LOW);
        digitalWrite(PIN12, HIGH);

    } else if (cam == 3) {
        // wiringPiI2CWriteReg8((0x70), (0x00), (0x04));
        iviic.write_control_register(0x04);

        digitalWrite(PIN7, LOW);
        digitalWrite(PIN11, HIGH);
        digitalWrite(PIN12, LOW);

    } else if (cam == 4) {
        // wiringPiI2CWriteReg8((0x70), (0x00), (0x08));
        iviic.write_control_register(0x08);
        
        digitalWrite(PIN7, HIGH);
        digitalWrite(PIN11, HIGH);
        digitalWrite(PIN12, LOW);
    } else {
        std::cout << "Invalid camera option passed: must be in (1,2,3,4)" << std::endl;

        return -1;
    }

    return cam;
}

char[] string_to_char(std::string str) {
    char result[str.size() + 1];
    for (unsigned int i = 0; i < str.size() ; i++ ) {
        result[i] = str.at(i);
    }

    result[str.size()] = '\0';

    return result;
}


// takes picture and gives it the name of the argument with .jpg appended
std::string camera::capture(std::string name) {
    std::string end (".jpg");
    std::string cmd ("raspistill -t 3 -o ");
    std::string command;
    std::string options (" --nopreview");
    std::string image_name;
    image_name = name + end;
    command = cmd + image_name + options;

    // convert string to char* for system command
    // char cmd_char[command.size() + 1];
    // for (unsigned int i = 0 ; i < command.size() ; i++) {
    //     cmd_char[i] = command.at(i);
    // }
    // cmd_char[command.size()] = '\0';

    char cmd_char = string_to_char(command);
    std::cout << cmd_char << std::endl;

    system(cmd_char);

    return image_name;
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

// takes pictures with camera 1-3 and naming them cam[cam number]_[iteration].jpg
Image[] capture_sequence() {
    // creates camera object
    camera cam;
    clock_t current_time;

    current_time = clock();

    // loops through the necessary 6 times to take pictures for OpNav
    for (int i = 1; i <= 6; i++) {

        // creates string from the variable i as a naming mechanism for the images taken
        std::string num_str;
        num_str = num_as_string(i);

        // captures the images for the ith iteration in the sequence
        cam.set_camera(1);
        cam.capture("cam1_" + num_str);

        cam.set_camera(2);
        cam.capture("cam2_" + num_str);

        cam.set_camera(3);
        cam.capture("cam3_" + num_str);
    }
    return 1;
}

int main() {

    // need to initialize I2C first before usage, this should all be done in the constructor of the camera object
    camera cam;

    cam.set_camera(1);
    cam.capture("test1");

    cam.set_camera(2);
    cam.capture("test2");

    cam.set_camera(3);
    cam.capture("test3");

    cam.set_camera(4);
    cam.capture("test4");
}


