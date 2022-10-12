# CC and CFLAGS are variables
CC = g++
CFLAGS = -c
OPTFLAGS = -O3

all	: bin/cb

bin/cb	: src/main.o src/Cyclebreak.o
	$(CC) $(OPTFLAGS) $^ -o $@
main.o	: src/main.cpp
	$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@
Cyclebreak.o	: src/Cyclebreak.cpp src/Cyclebreak.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $^ -o $@

clean:
	rm -rf src/*.o bin/*
