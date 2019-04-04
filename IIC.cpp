#include "IIC.h"

int iic_address = (0x70);
int iic_register = (0x00);

int iic_bus0 = (0x01);
int iic_bus1 = (0x02);
int iic_bus2 = (0x04);
int iic_bus3 = (0x08);

IIC::IIC(int iic_addr, int bus_enable) {
    iic_address = iic_addr;
    int config = bus_enable;
    // write(iic_register, config)
}

void IIC::write(int rgstr, int data) {
    // wiringPiI2CWrite(_register, data);
}

void IIC::write_control_register(int config) {
    write(iic_register, config);
}

int IIC::read() {
    // return wiringPiI2CRead(address);
    return iic_register;
}

int main() {
    IIC i2c = IIC(iic_address, iic_bus0);
}