#include "IIC.h"

int iic_address = (0x70);
int iic_register = (0x00);

int iic_bus0 = (0x01);
int iic_bus1 = (0x02);
int iic_bus2 = (0x04);
int iic_bus3 = (0x08);

// initializes I2C address, so it can be written to and read from
// Precondition: must run wiringPiI2CSetup(1) * on model A+
// run i2cdetect -y 1 to figure out the device number and use this as the argument for wiringPiI2CSetup(*) before running
IIC::IIC(int iic_addr, int bus_enable) {
    iic_address = wiringPiI2CSetup(iic_addr);
    int output = wiringPiI2CWriteReg8(iic_address, (0x00), bus_enable);
}

void IIC::write(int _register, int data) {
    wiringPiI2CWriteReg8(iic_address, _register, data);
}

void IIC::write_control_register(int config) {
    write(iic_register, config);
}

int IIC::read() {
    return wiringPiI2CRead(iic_address);
}

int IIC::read_control_register() {
    return read();
}