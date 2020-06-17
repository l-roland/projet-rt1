all : client1 client2 client3 client4 client5 server

client1 : client1.c
	gcc -Wall client1.c -o client1

client2 : client2.c
	gcc -Wall client2.c -o client2

client3 : client3.c
	gcc -Wall client3.c -o client3

client4 : client4.c
	gcc -Wall client4.c -o client4

client5 : client5.c
	gcc -Wall client5.c -o client5

server : server.c
	gcc -Wall server.c -o server

clean : 
	rm -rf client1 client2 client3 client4 client5 server