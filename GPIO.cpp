// class

#include <iostream>
#include <wiringPiI2C.h>
using namespace std;

class GPIO {
    int address;
    int bus_enable;
    int config;
    int width, height;
    int iic_register = (0x00);
    public:
        GPIO (int, int);
        void write(int, int);
        int read_byte();
        int read_control_register();
        void write_control_register();
};

// constructor to initialize address and the bus to enable
GPIO:: GPIO( int addr, int bus) {
    address = addr;
    bus_enable = bus;
    config = bus_enable;

    write(iic_register, config);
}

void write(int _register, int data) {
    int result = wiringPiI2CWrite(_register, data);
}

int read_byte() {
    return wiringPiI2CRead(this.address);
}

void write_control_register(config) {
    write(iic_register, config);
}

int main() {
    GPIO gpio ((0x70), (0x01));

    return 0;
}