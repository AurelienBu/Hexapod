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

void getup(int fd);
void sitdown(int fd);
void walk3X3(int fd);
void walkright(int fd);
void walkleft(int fd);
#endif
