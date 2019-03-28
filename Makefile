CC = g++
SRC = GPIO.cpp
OBJS = $(SRC:.c=.o)
TARGET = output
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
main.cpp: GPIO.cpp $(INCLUDE)
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -f *.o $(TARGET)