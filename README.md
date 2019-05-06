# RPiCam
Drivers for RPi Cameras with Multiplexer

# Installation and Setup

First, make sure that the Raspberry Pi is up to date by running the two commands:
$ sudo apt-get update</br>
$ sudo apt-get upgrade</br>

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

Must be initialized first. In order for the initalization to take effect, the RPi must reboot, so running ./init will reboot the RPi. Using init() does not reboot the computer, and it must still be restarted. Every time the RPi shuts down, you will need to reinitialize and reboot again. This is very unfortunate, but it seems to be a problem with the Multiplexer, and we could not make it work with the python code unless the RPi was restarted either. I'm unsure of the reason why, and it would be a huge improvement if this could be fixed. This was another big problem during development,

./init

#include <init.h>

init();



Include the camera file:
#include <camera.h>

Three functions, set_camera(int) to select one of the four cameras to feed through the multiplexer, capture(string) to capture a picture and name it based off the argument, and capture_sequence() to take pictures with each camera in succession (used by CisLunar Explorers Optical Navigation system).

capture_sequnce()

set_camera()

capture()


