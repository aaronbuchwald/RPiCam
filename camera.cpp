#include "camera.h"
#include <string.h>


IIC iviic = IIC((0x70), (0x01));
cout << "Starting..." << endl;

// wiringPi abstracts the physical pin numbers
// pin number counterparts documented here: https://hackage.haskell.org/package/wiringPi
// Assign the wiringPi pin numbers to the variables named for their physical pin numbering
int PIN7 = 7;
int PIN11 = 0;
int PIN12 = 1;


// writes data to the register at (0x70) and sets wiringPi pins to designate the correct camera
// camera 4 is available on multiplexer but not implemented here
// return cam number changed to on success
// returns -1 for an illegal argument
int set_camera(int cam) {
    if (cam == 1) {
        iviic.write_control_register((0x01));
        digitalWrite(PIN7, LOW);
        digitalWrite(PIN11, LOW);
        digitalWrite(PIN12, HIGH);

    } else if (cam == 2) {
        iviic.write_control_register((0x02));
        digitalWrite(PIN7, LOW);
        digitalWrite(PIN11, HIGH);
        digitalWrite(PIN12, HIGH);

    } else if (cam == 3) {
        iviic.write_control_register((0x04));
        digitalWrite(PIN7, HIGH);
        digitalWrite(PIN11, LOW);
        digitalWrite(PIN12, LOW);

    } else if (cam == 4) {
        // iviic.write_control_register((0x08));
        // assign GPIO pins

        cout << "No cam 4";
        return -1;
    } else {
        return -1;
    }

    return cam;
}


// takes picture and gives it the name of the argument with .jpg appended
std::string capture(std::string name) {
    std::string = name + ".jpg";
    system("raspistill -o " + full_name);

    return full_name;
}



