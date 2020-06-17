# Projet

*=>  Etape 1*  
- *Création d'un compte github personnel ( gratuit )*
- *Création et installation de votre clé SSH*
- *Apprendre à réaliser sous git les opérations suivantes :*
    - *Clone(modifié)*
    - *Commit*
    - *Push*
- *Pull*
- *Mettre en place un repository Git sur votre compte pour le projet*
- *Ajouter le compte SebDruon comme collaborateur à votre projet*

*=>  Etape 2*  
- *Comprendre la notion de pointeur ( si besoin, demander au prof de faire un petit topo a votre groupe )*
- *Mise en place d'un Makefile dans votre projet pour faciliter les compilations*

*=>  Etape 3*  
- *Se documenter sur la notion de socket, et leur utilisation en C* 
- *Ecrire un exemple client / serveur avec :*
    - *Le client qui envoie "coucou" au serveur*
    - *Le serveur qui répond "Bonjour" à chaque coucou reçu ( et rien si ce n'est pas un coucou)*


## Etape 1

### 1/ Création d'un compte github personnel

Je me crée un compte GitHub avec le pseudo l-roland. J’utiliserai mon mail etu.umontpellier.fr.

![](https://i.imgur.com/kXX1DQx.png)

### 2/ Création et installation de votre clé SSH

![](https://i.imgur.com/mGsZd8O.png)

```
root@louis-TUF:/home/louis# ssh-keygen -t rsa -b 4096
Generating public/private rsa key pair.
Enter file in which to save the key (/root/.ssh/id_rsa):
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /root/.ssh/id_rsa.
Your public key has been saved in /root/.ssh/id_rsa.pub.
The key fingerprint is:
SHA256:0a1RV3WCwe6UAhZx7+FmpR6haJDnAXL1u/uoAqmbctc root@louis-TUF
The key's randomart image is:
+---[RSA 4096]----+
...
+----[SHA256]-----+

root@louis-TUF:/home/louis# cat /root/.ssh/id_rsa.pub
ssh-rsa ...
```
![](https://i.imgur.com/EttnqlQ.png)

```
root@louis-TUF:/home/louis# ssh-add /root/.ssh/id_rsa
Identity added: /root/.ssh/id_rsa (root@louis-TUF)
```

### 3/ Mise en place du repository GitHub

![](https://i.imgur.com/93IEqvQ.png)

### 4/ Apprendre à réaliser des opérations sous git

#### 1- Clone
```
root@louis-TUF:/home/louis# git clone https://github.com/l-roland/projet-rt1
Cloning into 'projet-rt1'...
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (3/3), done.
```

#### 2- Commit
```
root@louis-TUF:/home/louis# cat salut
fichier test
 
root@louis-TUF:/home/louis# git config --global user.email louis.roland@etu.umontpellier.fr
 
root@louis-TUF:/home/louis# git init
Initialized empty Git repository in /home/louis/.git/
 
root@louis-TUF:/home/louis# git add salut
 
root@louis-TUF:/home/louis# git commit -m "commit test"
[master (root-commit) 75d26c1] commit test
 1 file changed, 1 insertion(+)
 create mode 100644 salut
```
#### 3- Pull
```
root@louis-TUF:/home/louis# git remote add origin https://github.com/l-roland/projet-rt1.git
root@louis-TUF:/home/louis# git pull origin master --allow-unrelated-histories
From https://github.com/l-roland/projet-rt1
 * branch            master     -> FETCH_HEAD
Merge made by the 'recursive' strategy.
 README.md | 1 +
 1 file changed, 1 insertion(+)
 create mode 100644 README.md
```

#### 4- Push
```
root@louis-TUF:/home/louis# git remote add origin https://github.com/l-roland/projet-rt1.git
root@louis-TUF:/home/louis# git push origin master
Username for 'https://github.com': l-roland
Password for 'https://l-roland@github.com':
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (5/5), 522 bytes | 522.00 KiB/s, done.
Total 5 (delta 0), reused 0 (delta 0)
To https://github.com/l-roland/projet-rt1.git
   48a349a..ce742f4  master -> master
```

![](https://i.imgur.com/cnzAEG6.png)

![](https://i.imgur.com/ECQnvwY.png)

### 5/ Ajout d’un collaborateur au projet

![](https://i.imgur.com/rvkedzW.png)

![](https://i.imgur.com/GYx3Dhf.png)


### 6/ Sitographie

- https://www.hostinger.fr/tutoriels/commandes-git/
- https://blog.stephane-robert.info/post/utiliser-ssh-github/
- https://www.educative.io/edpresso/the-fatal-refusing-to-merge-unrelated-histories-git-error
- https://stackoverflow.com/questions/51279044/fatal-origin-does-not-appear-to-be-a-git-repository

## Etape 2

### 1/ Notion de pointeur

Un pointeur est une variable contenant l'adresse d'une autre variable d'un type donné. La notion de pointeur fait souvent peur car il s'agit d'une technique de programmation très puissante, permettant de définir des structures dynamiques, c'est-à-dire qui évoluent au cours du temps (par opposition aux tableaux par exemple qui sont des structures de données statiques, dont la taille est figée à la définition). 

- Contenu du fichier ```pointeur.c```

```c
#include <stdio.h>
 
int main() {
 int a = 2;
 int *b = &a;
 printf("%p\n",b);
 printf("%d\n",*b);
 return 0;
}
```

- Compilation et lancement du programme

```
root@louis-TUF:/home/louis# gcc -Wall pointeur.c -o pointeur
root@louis-TUF:/home/louis# ./pointeur
0x7ffcb9635c2c
2
```


```
root@louis-TUF:/home/louis# git add pointeur.c
root@louis-TUF:/home/louis# git commit -m "Exemple pointeur"
root@louis-TUF:/home/louis# git push origin master
```

### 2/ Mise en place d’un makefile

- Exemple Makefile

```
<cible> : <dépendances>
        <commande>
```

- Contenu Makefile

```
pointeur : pointeur.c
        gcc -Wall pointeur.c -o pointeur
```

- Ajout de Makefile à GitHub

```
root@louis-TUF:/home/louis# git add Makefile
root@louis-TUF:/home/louis# git commit -m "Makefile programmes .c"
root@louis-TUF:/home/louis# git push origin master
```

### 3/ Sitographie
- https://www.lct.jussieu.fr/pagesperso/jpp/pointeurs.pdf
- https://www.youtube.com/watch?v=-riHEHGP2DU


## Etape 3


### 1/ Documentation socket

http://sdz.tdct.org/sdz/les-sockets.html

### 2/ Exemple Client/Serveur

- Contenu de ```Makefile```

```
all : pointeur client server
 
pointeur : pointeur.c
        gcc -Wall pointeur.c -o pointeur
 
client : client.c
        gcc -Wall client.c -o client
 
server : server.c
        gcc -Wall server.c -o server
 
clean:
        rm -rf pointeur client server
```

- Contenu de ```client.c```

```
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
```

- Contenu de ```server.c```

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

void main(){

	int sockfd;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;
	char buffer[1024];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Serveur PROJET\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	listen(sockfd, 5);
	printf("En écoute\n");
	newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
	recv(newSocket, buffer, 1024, 0);
	printf("Récéption : %s\n",buffer);
	if (strcmp(buffer,"coucou")==0){
		strcpy(buffer, "Bonjour");
		send(newSocket, buffer, strlen(buffer), 0);
		printf("Envoi : %s\n",buffer);
		printf("Fermeture du serveur\n");
	}
	else
	{
		printf("Fermeture du serveur\n");
	}
}
```

3/ Sitographie

- https://forums.commentcamarche.net/forum/affich-21222642-faire-un-if-avec-un-char
- http://sdz.tdct.org/sdz/les-sockets.html
- https://github.com/nikhilroxtomar/tcp-client-server-in-C

