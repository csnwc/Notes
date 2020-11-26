CFLAGS = `sdl-config --cflags` -O2 -Wall -Wextra -pedantic -ansi
INCS = neillsdl.h
TARGET = rl
SOURCES = neillsdl.c $(TARGET).c
LIBS =  `sdl-config --libs` -lm
CC = gcc


all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(WARNS) $(LIBS)

clean:
	rm -f $(TARGET)

run: all
	$(TARGET) 
