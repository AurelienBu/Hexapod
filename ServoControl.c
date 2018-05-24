/******************************************************************************
 *@file ServoControl.c                                                        *
 *                                                                            *
 *@author Aurelien Burdot                                                     *
 *                                                                            *
 *@email aurelien.burdot@gmail.com                                            *
 *                                                                            *
 *@brief This is software to control a hexapod over serial communication.     *
 *	 This program is design to work on a Raspberry Pi but should on           *
 *	 various linux platform.                                                  *
 *	 The program is made to control a Pololu Maestro 18 servos                *
 *                                                                            *
 *****************************************************************************/
#include "ServoControl.h"

/******************************************************************************
 * Function: ServosGetPosition                                                *
 * Param: int fd : file directory to the serial com                           *
 *         unsigned char channel : channel of the servos                      *
 * return: int : position of th servos                                        *
 * Brief: This function reads the position of the servos given by the channel *
 *                                                                            *
 *****************************************************************************/
int ServosGetPosition(int fd, unsigned char channel)
{
  unsigned char command[] = {0x90, channel};
  if(write(fd, command, sizeof(command)) == -1)
  {
    perror("error writing");
    return -1;
  }
 
  unsigned char response[2];
  if(read(fd,response,2) != 2)
  {
    perror("error reading");
    return -1;
  }
 
  return response[0] + 256*response[1];
}
 
/******************************************************************************
 * Function : ServosSetTarget                                                 *
 * Param : int fd : file directory to the serial com                          *
 *         unsigned char channel : channel of the servos                      *
 *         unsigned short target : position needed in quarter-microsecond     *
 * Brief : This function set the position of the servos given by the channel  *
 *                                                                            *
 *****************************************************************************/
int ServosSetTarget(int fd, unsigned char channel, unsigned short target)
{
  unsigned char command[] = {0x84, channel, target & 0x7F, target >> 7 & 0x7F};
  if (write(fd, command, sizeof(command)) == -1)
  {
    perror("error writing");
    return -1;
  }
  return 0;
}

/******************************************************************************
 * Function : SerialConfig                                                    *
 * Param : const char* SerialPort : SerialPort for serial communication       *
 *         int baud : baudrate for the serial communication                   *
 * return: int : file directory of the serial com                             *
 * Brief : This function configure the serial communication                   *
 *                                                                            *
 *****************************************************************************/
int SerialConfig(const char* SerialPort, int baud)
{
	const char * device = SerialPort; 

	int fd = open(device, O_RDWR | O_NOCTTY);
  	if (fd == -1)
  	{
    		perror(device);
    		return -1;
  	}
	struct termios options;
	tcgetattr(fd, &options);
	options.c_iflag &= ~(INLCR | IGNCR | ICRNL | IXON | IXOFF);
	options.c_oflag &= ~(ONLCR | OCRNL);
	options.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	switch(baud) {
	case 9600 : options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
		    break;
	case 115200 : options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
	              break;
	default : options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
		  break;
	}
	tcsetattr(fd, TCSANOW, &options);
	
	return fd;
}

