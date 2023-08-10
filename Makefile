CC = g++
CFLAGS = -std=c++11 -I./include

SRCDIR = ./src
INCDIR = ./include

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(SRCDIR)/%.o, $(SOURCES))

EXECUTABLE = run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) main.cpp
	$(CC) $(CFLAGS) -o $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/module.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: all clean
