#include "ServoControl.h"
#include "ServeurTCP.h"
#include "HexapodKinetic.h"
#include <sys/types.h>
#include <sys/syscall.h>
#include <pthread.h>

int initial = 0;

void * TCP_thread(void* arg);

int main()
{
 	
	int fd = SerialConfig("/dev/serial0", 9600);
	int ret = 0;
	pthread_t tcp_thread;
	if((ret = pthread_create (&tcp_thread, NULL,
				  TCP_thread, NULL)) != 0) {
		fprintf(stderr, "Erreur de Creation du Thread : ret = %d \n",
			ret);
	}

//	int position =0;
//	position = ServosGetPosition(fd, 11);
//	printf("Current position is %d.\n", position);

//	ServosSetTarget(fd, 11, 8000);

//	close(fd);
	//int fd = SerialConfig("/dev/serial0", 9600);
	//ServosSetTarget(fd, 11, 8000);
	//int hSocket = CreateTCPSrv();
	//int hSocketDiscute = ConnectClientTCP(hSocket);
	
	pthread_join(tcp_thread, NULL);
	fprintf(stderr,"fin thread\n");
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

void* TCP_thread(void* arg) {
	int hSocket = 0;
	int hSocketDiscute = 0;
	char* msgClient;
	msgClient = (char *) malloc(MAXSTRING * sizeof(char));
	fprintf(stderr,"Je suis dans le thread\n");
	hSocket = CreateTCPSrv();
	while(1) {
		hSocketDiscute = ConnectClientTCP(hSocket);
		ReceiveMsgTCP (hSocketDiscute, msgClient);
	}
	pthread_exit((void*)NULL);
}
