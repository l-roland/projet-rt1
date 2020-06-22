#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

void main(){
	
	int clientSocket;
	char msg[1024];
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	printf("Client PROJET\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("Connecté au Serveur\n");

	printf("Dites quelque chose : ");
  	scanf("%s", msg);
	strcpy(buffer, msg);
	send(clientSocket, buffer, strlen(buffer), 0);
	printf("Envoi : %s\n",buffer);
	if (strcmp(buffer,"coucou")==0){
		recv(clientSocket, buffer, 1024, 0);
		printf("Récéption : %s\n",buffer);
		printf("Fermeture du client\n");
	}
	else
	{
		printf("Fermeture du client\n");
	}
}
