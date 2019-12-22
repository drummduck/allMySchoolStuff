# Makefile for

CXX = g++
CFLAGS = -Wall -std=c++11
CURRENT = .

GOOGLETEST = ../googletest/googletest

LIBS = -L $(GOOGLETEST) -lgtest -lgtest_main -lpthread

StudentsTests:
	$(CXX) $(CFLAGS) -o StudentsTests Students.o StudentsTests.cpp -I$(GOOGLETEST)/include $(LIBS)

clean:
	rm StudentsTests

test:
	./StudentsTests

