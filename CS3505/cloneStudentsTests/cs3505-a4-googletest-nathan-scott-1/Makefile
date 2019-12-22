# Makefile for StudentsTests - testing students.o and students.h
#Scott Neville and Nathan Donaldson for CS 3505 Fall 2016

CXX = g++
CFLAGS = -Wall -std=c++11

GOOGLETEST = ../googletest/googletest

LIBS = -L $(GOOGLETEST) -lgtest -lgtest_main -lpthread

StudentsTests: StudentsTests.cpp Students.o
	$(CXX) $(CFLAGS) -o StudentsTests Students.o StudentsTests.cpp -I$(GOOGLETEST)/include $(LIBS)

test:
	./StudentsTests

clean:
	rm StudentsTests
