/******************************************************************************
 *@file control.h                                                            *
 *                                                                            *
 *@author Aurelien Burdot                                                     *
 *                                                                            *
 *@email aurelien.burdot@gmail.com                                            *
 *                                                                            *
 *@brief This is software to control a hexapod over serial communication.     *
 *	 This program is design to work on a Raspberry Pi but should on       *
 *	 various linux platform.                                              *
 *	 The program is made to control a Pololu Maestro 18 servos            *
 *                                                                            *
 *****************************************************************************/
#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

 
#ifdef _WIN32
#define O_NOCTTY 0
#else
#include <termios.h>
#endif


int ServosGetPosition(int fd, unsigned char channel);
int ServosSetTarget(int fd, unsigned char channel, unsigned short target);
int SerialConfig(const char* SerialPort, int baud);

#endif
