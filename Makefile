CC = g++
SRC = GPIO.cpp
CCFLAGS = -Wall -g

all: init camera

init: init.o IIC.o
	$(CC) $(CCFLAGS) -o init init.o IIC.o -lwiringPi

init.o: init.cpp IIC.h
	$(CC) $(CCFLAGS) -c init.cpp -lwiringPi

IIC.o: IIC.h -lwiringPi

# capture_sequence: capture_sequence.o camera.o
# 	$(CC) $(CCFLAGS) -o init init.o IIC.o -lwiringPi

# capture_sequence.o: capture_sequence.cpp camera.h
# 	$(CC) $(CCFLAGS) -c capture_sequence.cpp -lwiringPi

camera: camera.o -lwiringPi

camera.o: camera.h -lwiringPi


# OBJS = $(SRC:.c=.o)
# TARGET = output
# all: $(TARGET)
# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
# main.cpp: GPIO.cpp $(INCLUDE)
# 	$(CC) $(CFLAGS) main.cpp -lwiringPi
# clean:
# 	rm -f *.o $(TARGET)