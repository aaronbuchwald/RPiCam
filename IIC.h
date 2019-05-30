#ifndef _IIC_H
#define _IIC_H

#include <wiringPi.h>
#include <wiringPiI2C.h>

class IIC {
    public:
	IIC();
        IIC(int iic_addr, int bus_enable);
        void write(int rgstr, int data);
        int read();
        int read_control_register();
        void write_control_register(int config);
    private:
        int iic_address, iic_register;
        int iic_bus0, iic_bus1, iic_bus2, iic_bus3;
};

#endif
