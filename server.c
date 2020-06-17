#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/select.h>


int main(){
    int client[30];
    int nb_client=0;
	int sockfd, ret;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(4444);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");



	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 4444);

	if(listen(sockfd, 10) == 0){
		printf("[+]Listening....\n");
	}else{
		printf("[-]Error in binding.\n");
	}


	while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
        else
        {
            nb_client++;
            for (int i = 0; i < 5; i++) 
            {
                //if position is empty
                if( client[i] == 0 )
                {
                    client[i] = newSocket;
                    printf("Adding to list of sockets as %d\n" , i);
                    break;
                }
            }
        }
        
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
        printf("Nombre de clients connectés : %d\n",nb_client);
		if((childpid = fork()) == 0){
			close(sockfd);

			while(1){
				recv(newSocket, buffer, 1024, 0);
				printf("Récéption : %s\n",buffer);
                
	            if (strcmp(buffer,"coucou")==0){
		            strcpy(buffer, "Bonjour");
                    for (int i = 0; i < 5; i++) 
                    {
                        send(client[i], buffer, strlen(buffer),0);
                    }

		            
                    printf("Envoi : %s\n",buffer);
		            memset (buffer, 0, sizeof (buffer));
	            }
                else if (strcmp(buffer,"exit")==0){
                    printf("Client déconnecté\n");
                    nb_client--;
	            }
	            else 
	            {
		            printf("Pas d'envoi\n");
                    memset (buffer, 0, sizeof (buffer));
	            }
			}
		}

	}

	close(newSocket);


	return 0;
}

