#include "ServoControl.h"
#include "ServeurTCP.h"
#include "HexapodKinetic.h"

int initial = 0;

int main()
{
 
	int fd = SerialConfig("/dev/serial0", 9600);
//	int position =0;
//	position = ServosGetPosition(fd, 11);
//	printf("Current position is %d.\n", position);

//	ServosSetTarget(fd, 11, 8000);

//	close(fd);
	//int fd = SerialConfig("/dev/serial0", 9600);
	//ServosSetTarget(fd, 11, 8000);
	//int hSocket = CreateTCPSrv();
	//int hSocketDiscute = ConnectClientTCP(hSocket);
	char* msgClient;
	//msgClient = (char *) malloc(MAXSTRING * sizeof(char));
	fprintf(stderr,"Getup");	
	debout(fd);
	fprintf(stderr,"Getup..done");
	//sleep(1000);
	while(1) {
		//ReceiveMsgTCP (hSocketDiscute, msgClient);
		//fprintf(stderr, "Received %s\n", msgClient);
		//if(!(strcmp("fd+", msgClient))){						
			int j=0;
			fprintf(stderr,"walking");
			while(j<10){
				avancer3X3(fd);
				j++;
			}/*
	         j=0;
	         while(j<5){
	          avancer2X2X2();
	          j++;
	         }
	        //depLatLeft();*/
			sleep(2000);
			coucher(fd);
			sleep(5000);
	    //}
	}
	return 0;

}

