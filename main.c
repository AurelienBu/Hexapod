#define _GNU_SOURCE
#include "ServoControl.h"
#include "ServeurTCP.h"
#include "HexapodKinetic.h"
#include <sys/types.h>
#include <sys/syscall.h>
#include <pthread.h>

void* TCP_thread(void* arg);
pthread_mutex_t mutex;
int initial = 0;
char* cmd;

int main()
{
	/* Config Serial port*/
	int fd = SerialConfig("/dev/serial0", 9600);
	int ret = 0;
	pthread_t tcp_thread;
	/* Init mutex */
	pthread_mutex_init(&mutex, NULL);
	cmd = (char *) malloc(MAXSTRING * sizeof(char));
	/* Create Thread */
	if((ret = pthread_create (&tcp_thread, NULL,
				  TCP_thread, NULL)) != 0) {
		fprintf(stderr, "Erreur de Creation du Thread : ret = %d \n",
			ret);
	}
	/* Start the hexapod with sit down pose */
	pthread_mutex_lock(&mutex);
	strcpy(cmd, "bd+");
	pthread_mutex_unlock(&mutex);
	while(1) {
		pthread_mutex_lock(&mutex);
		/* Parse the cmd */
		if(strcmp(cmd, "fd+") == 0) {
			pthread_mutex_unlock(&mutex);
			fprintf(stderr,"walk\n");
			walk3X3(fd);
		}
		else if(strcmp(cmd, "s++") == 0) {
			pthread_mutex_unlock(&mutex);
			fprintf(stderr, "Stop..get up\n");
			getup(fd);
  	          	pthread_mutex_lock(&mutex);
            		strcpy(cmd, "wait");
            		pthread_mutex_unlock(&mutex);
		//	while(strcmp(cmd, "s++") == 0);
		}
		else if(strcmp(cmd, "bd+") == 0) {
			pthread_mutex_unlock(&mutex);
			fprintf(stderr, "Sit down\n");
			sitdown(fd);
			pthread_mutex_lock(&mutex);
			strcpy(cmd, "wait");
			pthread_mutex_unlock(&mutex);
		//	while(strcmp(cmd, "bd+") == 0);
		}
		else if(strcmp(cmd, "r++") == 0) {
			pthread_mutex_unlock(&mutex);
			fprintf(stderr, "right\n");
			walkright(fd);
		}
		 else if(strcmp(cmd, "l++") == 0) {
                        pthread_mutex_unlock(&mutex);
                        fprintf(stderr, "left\n");
                        walkleft(fd);
                }

		else if(strcmp(cmd, "wait") == 0) {
			pthread_mutex_unlock(&mutex);
		}
		else
			pthread_mutex_unlock(&mutex);
	usleep(100);
	}
	pthread_join(tcp_thread, NULL);
	return 0;

}

void* TCP_thread(void* arg) {
	int hSocket = 0;
	int hSocketDiscute = 0;
	char* msgClient;
	msgClient = (char *) malloc(MAXSTRING * sizeof(char));
	/* Create the TCP Server */ 
	hSocket = CreateTCPSrv();
	while(1) {
		/* Connect the client */
		hSocketDiscute = ConnectClientTCP(hSocket);
		/* Wait to received a command */
		ReceiveMsgTCP (hSocketDiscute, msgClient);
		pthread_mutex_lock(&mutex);
		/* Write the commande to the global variable */
		strcpy(cmd, msgClient);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit((void*)NULL);
}
