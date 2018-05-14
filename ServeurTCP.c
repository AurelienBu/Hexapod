/******************************************************************************
 *@file ServeurTCP.c                                                          *
 *                                                                            *
 *@author Aurelien Burdot                                                     *
 *                                                                            *
 *@email aurelien.burdot@gmail.com                                            *
 *                                                                            *
 *@brief Serveur TCP Linux     												  *
 *                                                                            *
 *****************************************************************************/
#include "ServeurTCP.h"

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

int SendMsgTCP (int hSocketDiscute, char* message) {
	if(send(hSocketDiscute, message, strlen("Ack"),0) == -1){
        perror("Erreur de send");
        //exit(-1);
        return -1;
    }
    return 1;
}

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
        return 1;
    }
        
}

int CloseSrvTCP (int hSocket, int hSocketDiscute) {
	close(hSocket);
	close(hSocketDiscute);
	return 1;

}
