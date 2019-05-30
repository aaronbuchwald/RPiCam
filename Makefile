CC = g++
SRC = GPIO.cpp
CCFLAGS = -Wall -g

all: init camera

init: init.o IIC.o
	$(CC) $(CCFLAGS) -o init init.o IIC.o -lwiringPi

init.o: init.cpp IIC.h
	$(CC) $(CCFLAGS) -c init.cpp -lwiringPi

IIC.o: IIC.h -lwiringPi

camera: camera.o IIC.o
	$(CC) $(CCFLAGS) -o camera camera.o IIC.o -lwiringPi

camera.o: camera.h IIC.h
	$(CC) $(CCFLAGS) -c camera.cpp -lwiringPi

IIC.o: IIC.h -lwiringPi

clean:
	rm *.o
