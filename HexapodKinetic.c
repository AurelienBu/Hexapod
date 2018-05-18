/******************************************************************************
 *@file kinetic.c                                                             *
 *                                                                            *
 *@author Aurelien Burdot                                                     *
 * based on Kevin Leveque code                                                                            *
 *@email aurelien.burdot@gmail.com                                            *
 *                                                                            *
 *@brief kinetic lib                                                                                                      *
 *                                                                            *
 *****************************************************************************/

#include "HexapodKinetic.h"

void getup(int fd){
  
  ServosSetTarget(fd, 10,5500);
  ServosSetTarget(fd, 13,5500);
  ServosSetTarget(fd, 16,5500);
  ServosSetTarget(fd, 1,6500);
  ServosSetTarget(fd, 4,6500);
  ServosSetTarget(fd, 7,6500);
  
  ServosSetTarget(fd, 11,5500);
  ServosSetTarget(fd, 14,5500);
  ServosSetTarget(fd, 17,5500);
  ServosSetTarget(fd, 2,6500);
  ServosSetTarget(fd, 5,6500);
  ServosSetTarget(fd, 8,6500);
  
  ServosSetTarget(fd, 9,6000);
  ServosSetTarget(fd, 12,6000);
  ServosSetTarget(fd, 15,6000);
  ServosSetTarget(fd, 0,6000);
  ServosSetTarget(fd, 3,6000);
  ServosSetTarget(fd, 6,6000);

  //usleep(1000 * 1000);
}

void sitdown(int fd){
  
  ServosSetTarget(fd, 10,8000);
  ServosSetTarget(fd, 13,8000);
  ServosSetTarget(fd, 16,8000);
  ServosSetTarget(fd, 1,4000);
  ServosSetTarget(fd, 4,4000);
  ServosSetTarget(fd, 7,4000);
  
  ServosSetTarget(fd, 11,8000);
  ServosSetTarget(fd, 14,8000);
  ServosSetTarget(fd, 17,8000);
  ServosSetTarget(fd, 2,4000);
  ServosSetTarget(fd, 5,4000);
  ServosSetTarget(fd, 8,4000);
  
  ServosSetTarget(fd, 9,6000);
  ServosSetTarget(fd, 12,6000);
  ServosSetTarget(fd, 15,6000);
  ServosSetTarget(fd, 0,6000);
  ServosSetTarget(fd, 3,6000);
  ServosSetTarget(fd, 6,6000);

  //usleep(1000*1000);
}

void walk3X3(int fd){
  getup(fd);
//lift up the leg
  ServosSetTarget(fd, 4,4000);
  ServosSetTarget(fd, 10,8000);
  ServosSetTarget(fd, 16,8000);
  ServosSetTarget(fd, 1,7000);
  usleep(200*1000);
//turn the leg
  ServosSetTarget(fd, 3,8000);
  ServosSetTarget(fd, 9,7000);
  ServosSetTarget(fd, 15,4000);

  ServosSetTarget(fd, 0,4000);
  ServosSetTarget(fd, 6,6000);
  ServosSetTarget(fd, 12,6000);
  usleep(200*1000);
//put down the leg
  ServosSetTarget(fd, 4,6500);
  ServosSetTarget(fd, 10,5500);
  ServosSetTarget(fd, 16,5500);
  ServosSetTarget(fd, 1,6000);
  usleep(200*1000);
  
//lift up the leg
  ServosSetTarget(fd, 1,4000);
  ServosSetTarget(fd, 7,4000);
  ServosSetTarget(fd, 13,8000);
  ServosSetTarget(fd, 10,5000);
  usleep(200*1000);
//turn the leg
  ServosSetTarget(fd, 3,4000);
  ServosSetTarget(fd, 9,8000);
  ServosSetTarget(fd, 15,6000);
  
  ServosSetTarget(fd, 0,5000);
  ServosSetTarget(fd, 6,8000);
  ServosSetTarget(fd, 12,4000);
  usleep(200*1000);
//put down the leg
  ServosSetTarget(fd, 1,6500);
  ServosSetTarget(fd, 7,6500);
  ServosSetTarget(fd, 13,5500);
  ServosSetTarget(fd, 10,6000);
  usleep(200*1000);
  
}
void walkright(int fd){ 
  getup(fd);

  //moving side walk right
  
  ServosSetTarget(fd,5,8000);
  ServosSetTarget(fd,11,8000);
  ServosSetTarget(fd,17,8000);
  usleep(200*1000);
  ServosSetTarget(fd,4,6500);
  ServosSetTarget(fd,10,7000);
  ServosSetTarget(fd,16,7000);
  usleep(200*1000);
  ServosSetTarget(fd,2,8000);
  ServosSetTarget(fd,8,8000);
  ServosSetTarget(fd,14,8000);
  usleep(200*1000);

  ServosSetTarget(fd,5,6000);
  ServosSetTarget(fd,11,6000);
  ServosSetTarget(fd,17,6000);
  ServosSetTarget(fd,4,6000);
  ServosSetTarget(fd,10,6000);
  ServosSetTarget(fd,16,6000);

  
  usleep(200*1000);
  ServosSetTarget(fd,1,5500);
  ServosSetTarget(fd,7,5500);
  ServosSetTarget(fd,13,7000);
  usleep(200*1000); 
}
void walkleft(int fd) {

  getup(fd);

  //moving side walk left

  ServosSetTarget(fd,14,8000);
  ServosSetTarget(fd,2,8000);
  ServosSetTarget(fd,8,8000);
  usleep(200*1000);
  ServosSetTarget(fd,13,6500);
  ServosSetTarget(fd,1,7000);
  ServosSetTarget(fd,7,7000);
  usleep(200*1000);
  ServosSetTarget(fd,11,8000);
  ServosSetTarget(fd,17,8000);
  ServosSetTarget(fd,5,8000);
  usleep(200*1000);

  ServosSetTarget(fd,14,6000);
  ServosSetTarget(fd,2,6000);
  ServosSetTarget(fd,8,6000);
  ServosSetTarget(fd,13,6000);
  ServosSetTarget(fd,1,6000);
  ServosSetTarget(fd,7,6000);


  usleep(200*1000);
  ServosSetTarget(fd,10,5500);
  ServosSetTarget(fd,16,5500);
  ServosSetTarget(fd,13,7000);
  usleep(200*1000);

}
