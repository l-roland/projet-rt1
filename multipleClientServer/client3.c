#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>


int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	char msg[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(4444);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Connected to Server.\n");
	while(1){		
		memset (buffer, 0, sizeof (buffer));
		printf("Dites quelque chose : ");
  		scanf("%s", msg);
		strcpy(buffer, msg);
		send(clientSocket, buffer, strlen(buffer), 0);
		printf("Envoi : %s\n",buffer);
		if (strcmp(buffer,"coucou")==0){
			recv(clientSocket, buffer, 1024, 0);
			printf("Récéption : %s\n",buffer);
		}
		else if (strcmp(buffer,"exit")==0){
			close(clientSocket);
			printf("Fermeture du client\n");
			exit(1);
		}
		else
		{
			printf("Pas de réception\n");
		}
		if (recv(clientSocket, buffer, 1024, 0)){
			printf("Récéption broadcast: %s\n",buffer);
		}
		else{
			printf("Pas de récéption broadcast: %s\n",buffer);
		}
	}

	return 0;
}
