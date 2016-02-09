#! /bin/sh
clear
rm -f a.out
g++ -std=c++11 main.cpp
if [ -f "a.out" ]; then
	clear
	./a.out
	rm -f a.out
fi