/******************************************************************************
 *@file ServeurTCP.c                                                          *
 *                                                                            *
 *@author Aurelien Burdot                                                     *
 *        Kevin Leveque                                                       *
 *@email aurelien.burdot@gmail.com                                            *
 *                                                                            *
 *@brief Serveur TCP Linux     												  *
 *                                                                            *
 *****************************************************************************/
#include "ServeurTCP.h"

/******************************************************************************
 * Function: CreateTCPSrv                                                     *
 * Param: NONE                                                                *
 *                                                                            *
 * return: int : socket                                                       *
 * Brief: Create a TCP serveur with the IP address of the computer            *
 *                                                                            *
 *****************************************************************************/
int CreateTCPSrv() {

	int hSocket;
	struct sockaddr_in adresseSocketServeur;


	/* Création de la socket */	
	hSocket = socket(AF_INET,SOCK_STREAM,0);
	if(hSocket == -1){
		perror("Erreur lors de la création de la socket !\n");
		exit(-1);
	}
	printf("Creation de la socket (%d)\n",hSocket);
	/* Préparation de la structure d adresse */	
	adresseSocketServeur.sin_family = AF_INET;
	adresseSocketServeur.sin_port = htons(PORT);
	//adresseSocketServeur.sin_addr.s_addr = inet_addr("192.168.89.49");
	adresseSocketServeur.sin_addr.s_addr = INADDR_ANY;
	bzero(&(adresseSocketServeur.sin_zero),8);


    /* Reliage la socket à l'adresse du serveur */
	if(bind(hSocket, (struct sockaddr *)&adresseSocketServeur, 
			sizeof(struct sockaddr)) == -1) {
		perror("Error bind");
	}
	return hSocket;

}

/******************************************************************************
 * Function: ConnectClientTCP                                                 *
 * Param: int hSocket : socket of the serveur                                 *
 *                                                                            *
 * return: int : socket to discute                                            *
 * Brief: Connect the serveur to the client                                   *
 *                                                                            *
 *****************************************************************************/
int ConnectClientTCP(int hSocket) {

	int hSocketDiscute;
	struct sockaddr_in adresseSocketClient;
	unsigned int taille_sockaddr;
	int L;

    /* Attendre qu'un client se connect */
	if((L=listen(hSocket, 20)) == -1) {
		perror("Erreur Listen");
		close(hSocket);
		exit(-1);
	}
	printf("Listen : %d\n",L);
	taille_sockaddr = sizeof(struct sockaddr);

    /* Accepter la connexion du client */
	if((hSocketDiscute=accept(hSocket, (struct sockaddr *)&adresseSocketClient,
							  (socklen_t *) &taille_sockaddr)) == -1) {
			perror("Erreur accept");
			close(hSocket);
			close(hSocketDiscute);
			exit(-1);
			
	}
	printf("Discute : %d \n",hSocketDiscute);
	return hSocketDiscute;
}

/******************************************************************************
 * Function: SendMsgTCP                                                       *
 * Param: int hSocketDiscute : socket for the communication                   *
 *        char* message : pointer to the message to send                      *
 * return: int : 1 if success / -1 fail                                       *
 * Brief: Send a message over TCP                                             *
 *                                                                            *
 *****************************************************************************/
int SendMsgTCP (int hSocketDiscute, char* message) {
	if(send(hSocketDiscute, message, strlen("Ack"),0) == -1){
		perror("Erreur de send");
		//exit(-1);
		return -1;
	}
	return 1;
}

/******************************************************************************
 * Function: ReceiveMsgTCP                                                    *
 * Param: int hSocketDiscute : socket for the communication                   *
 *        char* msgClient : pointer to the varaible to save the message       *
 * return: int : 1 if success / -1 fail                                       *
 * Brief: receive a message over TCP                                          *
 *                                                                            *
 *****************************************************************************/
int ReceiveMsgTCP (int hSocketDiscute, char* msgClient) {
	//char *msgClient;
	//msgClient = (char *) malloc(MAXSTRING * sizeof(char));
	if(recv(hSocketDiscute, msgClient, 256, 0) == -1){
		perror("Erreur recv");
		return -1;
	}
	/* blocage par adresse ip */
	else {
		fprintf(stderr,"Received : %s\n",msgClient);
		eturn 1;
	}
}

/******************************************************************************
 * Function: CloseSrvTCP                                                      *
 * Param: int hSocketDiscute : socket for the communication                   *
 *        int hSocket : socket of the server                                  *
 * return: int : 1                                                            *
 * Brief: Close all socket                                                    *
 *                                                                            *
 *****************************************************************************/
int CloseSrvTCP (int hSocket, int hSocketDiscute) {
	close(hSocket);
	close(hSocketDiscute);
	return 1;

}
