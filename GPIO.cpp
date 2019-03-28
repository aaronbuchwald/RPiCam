// class

#include <iostream>
#include <wiringPiI2C.h>
using namespace std;

class GPIO {
    int address;
    int bus_enable;
    int config;
    int width, height;
    int iic_register;
    public:
        GPIO (int, int);
        void write(int, int);
        int read_byte();
        int read_control_register();
        void write_control_register();
};

// constructor to initialize address and the bus to enable
GPIO:: GPIO( int addr, int bus) {
    iic_register = (0x00);
    address = addr;
    bus_enable = bus;
    config = bus_enable;

    write(iic_register, config);
}

void write(int _register, int data) {
    int result = wiringPiI2CWrite(_register, data);
}

int GPIO::read_byte(int address) {
    return wiringPiI2CRead(address);
}

void write_control_register(int iic_register, int config) {
    write(iic_register, config);
}

int main() {
    GPIO gpio ((0x70), (0x01));

    return 0;
}