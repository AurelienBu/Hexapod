# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gcc
CFLAGS  = -g -Wall

#
default: Hexapod


Hexapod:  main.o ServeurTCP.o ServoControl.o HexapodKinetic.o
	$(CC) $(CFLAGS) -o Hexapod main.o ServeurTCP.o ServoControl.o HexapodKinetic.o -D_REENTRANT -lpthread


main.o:  main.c ServeurTCP.h ServoControl.h HexapodKinetic.h
	$(CC) $(CFLAGS) -c main.c -D_REENTRANT -lpthread


ServeurTCP.o:  ServeurTCP.c ServeurTCP.h 
	$(CC) $(CFLAGS) -c ServeurTCP.c


ServoControl.o:  ServoControl.c ServoControl.h
	$(CC) $(CFLAGS) -c ServoControl.c

HexapodKinetic.o:  HexapodKinetic.c HexapodKinetic.h
	$(CC) $(CFLAGS) -c HexapodKinetic.c

clean: 
	$(RM) count *.o *~
