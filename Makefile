# A makefile
CXX = clang++
CFLAGS = --std=c++11 -Wall -Wextra -g

default: main

debug: CFLAGS += -DDEBUG
debug: default 

main: main.cpp basicfs.o direntry.o inode.o
	$(CXX) $(CFLAGS) -o main main.cpp direntry.o basicfs.o inode.o

basicfs.o: basicfs.cpp basicfs.hpp
	$(CXX) $(CFLAGS) -c basicfs.cpp

direntry.o: direntry.cpp direntry.hpp
	$(CXX) $(CFLAGS) -c direntry.cpp

inode.o: inode.cpp inode.hpp
	$(CXX) $(CFLAGS) -c inode.cpp

clean:
	@rm -rf main *.o
