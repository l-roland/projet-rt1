all : pointeur client server

pointeur : pointeur.c
	gcc -Wall pointeur.c -o pointeur

client : client.c
	gcc -Wall client.c -o client

server : server.c
	gcc -Wall server.c -o server

clean:
	rm -rf pointeur client server
