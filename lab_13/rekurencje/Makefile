CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = potega

all: $(TARGET)

$(TARGET): potega.o
	$(CC) $(CFLAGS) -o $(TARGET) potega.o

potega.o: potega.c
	$(CC) $(CFLAGS) -c potega.c

clean:
	rm -f $(TARGET) potega.o

.PHONY: all clean