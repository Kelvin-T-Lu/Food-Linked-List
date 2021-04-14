#Kelvin Lu 
#Project 3 Make file
#CS 262 Lab 205

CC  = gcc
OPTS = -O0
DEBUG = -g -Wall

TARGET = Project3_klu21_205
OBJS = *.o
CFLAGS = $(OPTS) $(DEBUG)



all: $(TARGET)

$(TARGET) : orderList_klu21_205.o Project3_klu21_205.o
	$(CC) $(CFLAGS) -o $@ $^

orderList_klu21_205.o : orderList_klu21_205.c orderList_klu21_205.h
	$(CC) $(CFLAGS) -c $< -o $@

Project3_klu21_205.o : Project3_klu21_205.c orderList_klu21_205.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)
cleanall: 
	rm -f $(OBJS)
	rm -f $(TARGET)


