CC = g++
CFLAGS = -Wall -std=c++11

LIBHARU = ../libharu/src
INCLUDE = ../libharu/include
CURRENT = .

spiralPDF : Spiral.o HaruPDF.o spiralPDF.cpp
				$(CC) $(CFLAGS) -L$(LIBHARU) -o spiralPDF spiralPDF.cpp Spiral.o HaruPDF.o -lhpdfs -lz -lm -lstdc++

Spiral.o : Spiral.cpp $(CURRENT)/Spiral.h $(CURRENT)/HaruPDF.h 
				$(CC) $(CFLAGS) -I$(CURRENT) -I$(CURRENT) -c Spiral.cpp 

HaruPDF.o : HaruPDF.cpp $(CURRENT)/HaruPDF.h 
				$(CC) $(CFLAGS) -I$(CURRENT) -c HaruPDF.cpp

clean:
	rm spiralPDF *.o

test:
	./spiralPDF



