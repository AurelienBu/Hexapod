/******************************************************************************
 *@file kinetic.h                                                             *
 *                                                                            *
 *@author Aurelien Burdot                                                     *
 * based on Kevin Leveque code                                                                            *
 *@email aurelien.burdot@gmail.com                                            *
 *                                                                            *
 *@brief kinetic lib           												  *
 *                                                                            *
 *****************************************************************************/
#ifndef SERVEURTCP_H
#define SERVEURTCP_H

#include "ServoControl.h"
#include <unistd.h>

void debout(int fd);
void coucher(int fd);
void avancer3X3(int fd);
void walkleft(int fd);
#endif
