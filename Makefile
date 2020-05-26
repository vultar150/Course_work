CC := g++
CFLAGS := -c -Wall -std=c++11
DIR := src/
OBJECTS_LIST := main.o classes.o functions.o tinyxml2.o
OBJECTS := $(addprefix $(DIR), $(OBJECTS_LIST))
ALG := novel_algorithm


all: $(ALG)


novel_algorithm: $(OBJECTS)
	$(CC) $(notdir $(OBJECTS)) -o $@ 


%.o: %.cpp
	$(CC) $(CFLAGS) $^


clean:
	rm -rf  *.o $(ALG)
