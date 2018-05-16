#include "ServoControl.h"
#include "ServeurTCP.h"
#include "HexapodKinetic.h"

int initial = 0;

int main()
{
 
	/*int fd = SerialConfig("/dev/ACM0", 9600);
	int position =0;
	position = ServosGetPosition(fd, 5);
	printf("Current position is %d.\n", position);

	ServosSetTarget(fd, 5, 8000);

	close(fd);*/
	/*int hSocket = CreateTCPSrv();
	int hSocketDiscute = ConnectClientTCP(hSocket);*/
	int fd = SerialConfig("/dev/ACM0", 9600);
	while(1) {
		if(!initial){
			debout(fd);
			sleep(1000);
			int j=0;
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
	    }
	}
	return 0;

}

