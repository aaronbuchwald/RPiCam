#include "IIC.h"

int iic_address = (0x70);
int iic_register = (0x00);


IIC::IIC() {
    iic_address = wiringPiI2CSetup((0x70));
    if (iic_address < 0) {
	throw "IIC Setup failed";
    }
    else {
	int write = wiringPiI2CWriteReg8(iic_address, (0x00), (0x01));
	if (write < 0) {
	    throw "Write failed";
	}
    }
}

// initializes I2C address, so it can be written to and read from
// Precondition: must run wiringPiI2CSetup(1) * on model A+
// run i2cdetect -y 1 to figure out the device number and use this as the argument for wiringPiI2CSetup(*) before running
IIC::IIC(int iic_addr, int bus_enable) {

    iic_bus0 = (0x01);
    iic_bus1 = (0x02);
    iic_bus2 = (0x04);
    iic_bus3 = (0x08);
    int default_iic_address = iic_address;
    int default_bus_enable = iic_bus0;

    iic_address = wiringPiI2CSetup(iic_addr);
    int result = wiringPiI2CWriteReg8(iic_address, (0x00), bus_enable);
    if ( !(iic_address >= 0 && result >= 0)) {
	throw "IIC setup error";
    }
}

// uses the iic_address given to the constructor
// write data to the address at given reigster
int IIC::write(int _register, int data) {
    return wiringPiI2CWriteReg8(iic_address, _register, data);
}

// write to the register (0x00) the data given by config
int IIC::write_control_register(int config) {
    return write(iic_register, config);
}

// write_byte_data address is the building, the register is the apartment number, and the data is the letter
// wiringPiI2CWriteReg8()


// reads byte date at the address given by the constructor
int IIC::read() {
    return wiringPiI2CRead(iic_address);
}

int IIC::read_control_register() {
    return read();
}
