#include "HexapodKinetic.h"

void debout(int fd){
  
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

  sleep(500);
}

void coucher(int fd){
  
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

  sleep(500);
}

void avancer3X3(int fd){
//lever les pattes
  ServosSetTarget(fd, 4,4000);
  ServosSetTarget(fd, 10,8000);
  ServosSetTarget(fd, 16,8000);
  ServosSetTarget(fd, 1,7000);
  sleep(200);
//touner les pattes
  ServosSetTarget(fd, 3,8000);
  ServosSetTarget(fd, 9,7000);
  ServosSetTarget(fd, 15,4000);

  ServosSetTarget(fd, 0,4000);
  ServosSetTarget(fd, 6,6000);
  ServosSetTarget(fd, 12,6000);
  sleep(200);
//poser les pattes
  ServosSetTarget(fd, 4,6500);
  ServosSetTarget(fd, 10,5500);
  ServosSetTarget(fd, 16,5500);
  ServosSetTarget(fd, 1,6000);
  sleep(200);
  
//lever les pattes
  ServosSetTarget(fd, 1,4000);
  ServosSetTarget(fd, 7,4000);
  ServosSetTarget(fd, 13,8000);
  ServosSetTarget(fd, 10,5000);
  sleep(200);
//touner les pattes
  ServosSetTarget(fd, 3,4000);
  ServosSetTarget(fd, 9,8000);
  ServosSetTarget(fd, 15,6000);
  
  ServosSetTarget(fd, 0,5000);
  ServosSetTarget(fd, 6,8000);
  ServosSetTarget(fd, 12,4000);
  sleep(200);
//poser les pattes
  ServosSetTarget(fd, 1,6500);
  ServosSetTarget(fd, 7,6500);
  ServosSetTarget(fd, 13,5500);
  ServosSetTarget(fd, 10,6000);
  sleep(200);
  
}