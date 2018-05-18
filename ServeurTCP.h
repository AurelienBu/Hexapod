/******************************************************************************
 *@file ServeurTCP.h                                                          *
 *                                                                            *
 *@author Aurelien Burdot                                                     *
 *        Kevin Leveque                                                       *
 *@email aurelien.burdot@gmail.com                                            *
 *                                                                            *
 *@brief Serveur TCP Linux     												  *
 *                                                                            *
 *****************************************************************************/
#ifndef SERVEURTCP_H
#define SERVEURTCP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/sockios.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define PORT 65000
#define MAXSTRING 100

int CloseSrvTCP (int hSocket, int hSocketDiscute);
int ReceiveMsgTCP (int hSocketDiscute, char* msgClient);
int SendMsgTCP (int hSocketDiscute, char* message);
int ConnectClientTCP(int hSocket);
int CreateTCPSrv();

#endif
