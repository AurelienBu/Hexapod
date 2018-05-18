/******************************************************************************
 *@file hexapod.ino                                                           *
 *                                                                            *
 *@author Kevin Leveque                                                       *
 *                                                                            *
 *@brief hexapod software prototype                                           *
 *                                                                            *
 *****************************************************************************/
/*This example also assumes you have connected your Arduino to your
Maestro appropriately. If you have not done so, please see
https://github.com/pololu/maestro-arduino for more details on how
to make the connection between your Arduino and your Maestro. */

#include <PololuMaestro.h>
#define MAXMOTOR 18
/* On boards with a hardware serial port available for use, use
that port to communicate with the Maestro. For other boards,
create a SoftwareSerial object using pin 10 to receive (RX) and
pin 11 to transmit (TX). */
#ifdef SERIAL_PORT_HARDWARE_OPEN
  #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
#else
  #include <SoftwareSerial.h>
  SoftwareSerial maestroSerial(10, 11);
#endif

/* Next, create a Maestro object using the serial port.

Uncomment one of MicroMaestro or MiniMaestro below depending
on which one you have. */
MicroMaestro maestro(maestroSerial);
//MiniMaestro maestro(maestroSerial);

bool initial;

void debout();
void coucher();
void avancer3X3();

int j;

void setup()
{
  // Set the serial baud rate.
  maestroSerial.begin(9600);
  for(int i=0;i<MAXMOTOR;i++){
    maestro.setSpeed(i, 50);
    maestro.setAcceleration(i,100);
  }
  initial=false;

 
}

void loop()
{
     if(!initial){
          debout();
          delay(1000);
         j=0;
         while(j<10.){
          avancer3X3();
          j++;
         }/*
         j=0;
         while(j<5){
          avancer2X2X2();
          j++;
         }
        //depLatLeft();*/
         delay(2000);
         coucher();
         delay(5000);
     }
    
}
void debout(){
  
  maestro.setTarget(10,5500);
  maestro.setTarget(13,5500);
  maestro.setTarget(16,5500);
  maestro.setTarget(1,6500);
  maestro.setTarget(4,6500);
  maestro.setTarget(7,6500);
  
  maestro.setTarget(11,5500);
  maestro.setTarget(14,5500);
  maestro.setTarget(17,5500);
  maestro.setTarget(2,6500);
  maestro.setTarget(5,6500);
  maestro.setTarget(8,6500);
  
  maestro.setTarget(9,6000);
  maestro.setTarget(12,6000);
  maestro.setTarget(15,6000);
  maestro.setTarget(0,6000);
  maestro.setTarget(3,6000);
  maestro.setTarget(6,6000);

  delay(500);
  initial=true;
}

void coucher(){
  
  maestro.setTarget(10,8000);
  maestro.setTarget(13,8000);
  maestro.setTarget(16,8000);
  maestro.setTarget(1,4000);
  maestro.setTarget(4,4000);
  maestro.setTarget(7,4000);
  
  maestro.setTarget(11,8000);
  maestro.setTarget(14,8000);
  maestro.setTarget(17,8000);
  maestro.setTarget(2,4000);
  maestro.setTarget(5,4000);
  maestro.setTarget(8,4000);
  
  maestro.setTarget(9,6000);
  maestro.setTarget(12,6000);
  maestro.setTarget(15,6000);
  maestro.setTarget(0,6000);
  maestro.setTarget(3,6000);
  maestro.setTarget(6,6000);

  delay(500);
}

void avancer3X3(){
//lever les pattes
  maestro.setTarget(4,4000);
  maestro.setTarget(10,8000);
  maestro.setTarget(16,8000);
  maestro.setTarget(1,7000);
  delay(200);
//touner les pattes
  maestro.setTarget(3,8000);
  maestro.setTarget(9,7000);
  maestro.setTarget(15,4000);

  maestro.setTarget(0,4000);
  maestro.setTarget(6,6000);
  maestro.setTarget(12,6000);
  delay(200);
//poser les pattes
  maestro.setTarget(4,6500);
  maestro.setTarget(10,5500);
  maestro.setTarget(16,5500);
  maestro.setTarget(1,6000);
  delay(200);
  
//lever les pattes
  maestro.setTarget(1,4000);
  maestro.setTarget(7,4000);
  maestro.setTarget(13,8000);
  maestro.setTarget(10,5000);
  delay(200);
//touner les pattes
  maestro.setTarget(3,4000);
  maestro.setTarget(9,8000);
  maestro.setTarget(15,6000);
  
  maestro.setTarget(0,5000);
  maestro.setTarget(6,8000);
  maestro.setTarget(12,4000);
  delay(200);
//poser les pattes
  maestro.setTarget(1,6500);
  maestro.setTarget(7,6500);
  maestro.setTarget(13,5500);
  maestro.setTarget(10,6000);
  delay(200);
  
}
void avancer2X2X2(){
  //pattes: gauche arriere/ droit milieu
  maestro.setTarget(1,4000);
  maestro.setTarget(13,8000);
  delay(200);
  maestro.setTarget(0,8000);
  maestro.setTarget(12,4000);
  //pattes: gauche avant/ droit arriere
  maestro.setTarget(6,6000);
  maestro.setTarget(9,6000);
  delay(200);

  maestro.setTarget(1,6500);
  maestro.setTarget(13,5500);
  delay(200);

  //pattes: gauche milieu/ droit avant
  maestro.setTarget(4,4000);
  maestro.setTarget(16,8000);
  delay(200);
  maestro.setTarget(3,8000);
  maestro.setTarget(15,4000);
  //pattes: gauche arriere/ droit milieu
  maestro.setTarget(0,6000);
  maestro.setTarget(12,6000);
  delay(200);

  maestro.setTarget(4,6500);
  maestro.setTarget(16,5500);
  delay(200);

  //pattes: gauche avant/ droit arriere
  maestro.setTarget(7,5000);
  maestro.setTarget(10,7000);
  delay(200);
  maestro.setTarget(6,8000);
  maestro.setTarget(9,4000);
  //pattes: gauche avant/ droit arriere
  maestro.setTarget(3,6000);
  maestro.setTarget(15,6000);
  delay(200);

  maestro.setTarget(7,6500);
  maestro.setTarget(10,5500);
  delay(200);
  
  
}

void attaque(){ 
  maestro.setTarget(0,7000);
  maestro.setTarget(1,4000);
  maestro.setTarget(2,5500);
  maestro.setTarget(3,6000);
  maestro.setTarget(4,8000);
  maestro.setTarget(5,7500);
  maestro.setTarget(6,6000);
  maestro.setTarget(7,4000);
  maestro.setTarget(8,8000);
  maestro.setTarget(9,6000);
  maestro.setTarget(10,8000);
  maestro.setTarget(11,6500);
  maestro.setTarget(12,5000);
  maestro.setTarget(13,4000);
  maestro.setTarget(14,5000);
  delay(200);
}

void depLatLeft(){ 
  debout();

  //Depalcement 3X3 coté
  
  maestro.setTarget(5,8000);
  maestro.setTarget(11,8000);
  maestro.setTarget(17,8000);
  delay(200);
  maestro.setTarget(4,6500);
  maestro.setTarget(10,7000);
  maestro.setTarget(16,7000);
  delay(200);
  maestro.setTarget(2,8000);
  maestro.setTarget(8,8000);
  maestro.setTarget(14,8000);
  delay(200);

  maestro.setTarget(5,6000);
  maestro.setTarget(11,6000);
  maestro.setTarget(17,6000);
  maestro.setTarget(4,6000);
  maestro.setTarget(10,6000);
  maestro.setTarget(16,6000);

  
  delay(200);
  maestro.setTarget(1,5500);
  maestro.setTarget(7,5500);
  maestro.setTarget(13,7000);
  delay(200);

  
  
}
void depLatRight(){ 

}
