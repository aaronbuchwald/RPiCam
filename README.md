# RPiCam
Drivers for RPi Cameras with Multiplexer

# Installation and Setup

First, make sure that the Raspberry Pi is up to date by running the two commands:
$ sudo apt-get update
$ sudo apt-get upgrade

RPiCam depends on I2C and Camera to be enabled on the Raspberry Pi. You can set this up in two ways:

With RPi GUI:

1) Click Menu in the top left corner
2) Select Preferences
3) Select Preferences
4) Make sure that both i2c and Camera are enabled

From the command line:

$ raspi-config
Ensure that i2c and camera are enabled.

Next, refer to the installation instructions for the wiringPi library to ensure that your system has it installed correctly: http://wiringpi.com/download-and-install/

It should come pre-installed, but errors often occur and you may have to delete and reinstall the package.


# Notes

RPiCam is derived from the open source python library released by the manufacturer of the multiplexer here: https://github.com/ivmech/ivport-v2.

It is poorly documented and there are two iterations, which can be difficult to understand and difficult to translate into C++ with the wiringPi library. One of the problems I ran into was that it refers to different GPIO pins in different places (in the code and in examples) about which must be manipulated to select cameras.

Physical GPIO pins 7, 11, and 12 are manipulated to select from the four camera inputs on the multiplexer. Because the ivport-v2 github was poorly documented, I've redone it here and have found that this is the correct way to select cameras for the Multiplexer V2.



# Usage

./init

#include <init.h>

init();



Include the camera file:
#include <camera.h>

capture_sequnce()


