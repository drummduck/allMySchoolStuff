# Makefile for Trie.h, Trie.cpp, TrieTest.cpp, as well as the TrieTest executable.

CC = g++
CFLAGS = -Wall -std=c++11

CURRENT = .

TrieTest : Trie.o Node.o TrieTest.cpp
				$(CC) $(CFLAGS) -o TrieTest TrieTest.cpp Trie.o Node.o

Trie.o : Trie.cpp $(CURRENT)/Trie.h $(CURRENT)/Node.h
				$(CC) $(CFLAGS) -I$(CURRENT) -I$(CURRENT) -c Trie.cpp 

Node.o: Node.cpp $(CURRENT)/Node.h
				$(CC) $(CFLAGS) -I$(CURRENT) -c Node.cpp

clean:
	rm TrieTest *.o

Debug: TrieTest.cpp Node.cpp Trie.cpp
		g++ -g -std=c++11 TrieTest.cpp Node.cpp Trie.cpp

test:
	./TrieTest
