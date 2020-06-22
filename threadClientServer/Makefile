all : client server

client : client.c
	gcc -Wall client.c -o client -lpthread

server : server.c
	gcc -Wall server.c -o server -lpthread

clean:
	rm -rf client server
