CC = g++
SRC = GPIO.cpp
CCFLAGS = -Wall -g


init: init.o IIC.o
	$(CC) $(CCFLAGS) -o init init.o IIC.o -lwiringPi

init.o: init.cpp IIC.h
	$(CC) $(CCFLAGS) -c init.cpp -lwiringPi

IIC.o: IIC.h -lwiringPi

# OBJS = $(SRC:.c=.o)
# TARGET = output
# all: $(TARGET)
# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
# main.cpp: GPIO.cpp $(INCLUDE)
# 	$(CC) $(CFLAGS) main.cpp -lwiringPi
# clean:
# 	rm -f *.o $(TARGET)