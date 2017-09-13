CC = g++
FILES = main.cpp 
OPTIONS = -std=c++11 -Ofast

#main section
main: $(FILES)
	$(CC) $(OPTIONS) $(FILES) -o main

clear:
	rm -f main