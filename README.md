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

*=>  Etape 4*
- *tester votre programme avec 1 serveur et 5 clients simultanés*
- *modifier votre programme afin que tous les clients reçoivent le "bonjour" lorsque l'un d'entre eux emet un coucou*

*=>  Etape 5*
- *Définir ( oui oui sur le papier ) le protocole qui sera implémenté par vos clients et serveurs. Vous donnerez le format des messages échangés, les informations transmises, le déroulement des conversations types que vous attendez. Inspirez vous de MQTT.*
- *Vous ajouterez ce document en pdf à votre projet*

*=>  Etape 6*
- *Implementer, la partie de votre protocole qui correspond à l'inscription des clients sur le serveur et aux différents flux.*

*=>  Etape 7*
- *Implémenter le desabonnement des clients.*
- *Faire en sorte que le client ( et le serveur ) soit ergonomique en utilisant des parametres sur la ligne de commande*

## Etape 1

### 1/ Création d'un compte github personnel

Je me crée un compte GitHub avec le pseudo l-roland.

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

### 1/ Sitographie

- https://forums.commentcamarche.net/forum/affich-21222642-faire-un-if-avec-un-char
- http://sdz.tdct.org/sdz/les-sockets.html
- https://github.com/nikhilroxtomar/tcp-client-server-in-C

## Etape 4

### 1/ Sitographie

- https://github.com/nikhilroxtomar/Chatroom-in-C

## Etape 5 

### 1/ Protocole
- Le protocole utilisé pour le client/serveur est le TCP (layer Transport) car SOCK_STREAM est utilisé. Si on veut utiliser de l'UDP on utilisera SOCK_DGRAM.

- TCP : Le protocole TCP est un protocole dit connecté. Il contrôle si le paquet est arrivé à destination si ce n'est pas le cas il le renvoie. 

- UDP : À la différence de TCP, UDP est un protocole en mode non connecté, il ne vérifie pas si le paquet est arrivé à destination.

### 2/ Format
- En ce qui concerne le format des messages evoyés, tous ces messages échangés entre le serveur et les différents clients seront stockés dans la chaîne de caractères (char) buffer que l'on a initialisé avec une taille de 2048, ce qui sera largement suffisant pour envoyer même un long message.

- Lors de l'envoi, le buffer va calculer le nombre de caractère insérés par l'utilsiateur afin d'en déduire la taille de la chaîne de caractères pour ne pas qu'elle fasse tout le temps 2048 en taille.

- On retrouve aussi du int pour le port ou la validation de socket, une structure pour les paramètres et la connexion de sockets ou encore une variable pthread_t qui va gérer les différents threads.

### 3/ Diagramme UML 1 serveur 2 clients

![](https://imgur.com/wVeNMTP.png)

### 4/ Algorithme simplifié du serveur
```
début
	ajout des librairies socket et pthread + autres librairies pour le fonctionnement du programme
	déclaration de la taille du buffer à 2048
	déclaration de la variable sub à 0
	déclaration du nombre max de client à 100
	déclaration des paramètres du socket
		AF_INET <- IPv4
		SOCK_STREAM <- TCP
		PORT <- 4444
		IP <- 127.0.0.1 (loopback)
	si mauvaise initialiation, mauvaise liaison client/serveur et mauvaise écoute du socket
		afficher erreur et quitter
	sinon
		continuer le programme
	tant que 1
		quand un client se connecte au serveur, on ajoute 1 au nombre max de client puis on crée un thread pour ce client.
		limite utilisation du CPU à 1
		si récéption de username client stocké dans le buffer
			name <- username client
			envoyer à tous les clients connectés que le client est connecté
		sinon
			afficher erreur
		formatage du buffer
		tant que 1
			initialisation de la variable recep
			si réception  message stocké dans le buffer > 0
				si longueur du buffer > 0
					si buffer = "coucou"
						buffer <- Bonjour
						envoi à tous les clients le message contenu dans le buffer (cad Bonjour)
					sinon
						envoi du message contenu dans le buffer au client qui a envoyé le message
					fin si
			sinon si réception message stocké dans le buffer == 0 ou si buffer = "exit")
				buffer <- <nom_client> a quitté le serveur
				envoi à tous les clients le message contenu dans le buffer
				on enlève 1 au nombre max de clients
				
			sinon si buffer="sub <username_clientX>"
				créer un thread de subscription
				sub <- +1
				envoyer les messages émis par username_clientX au clients abonnés quand il en envoie un
			sinon si buffer="unsub <username_clientX>"
				fermer le thread de subscription
				sub <- -1
				ne plus envoyer les messages émis par username_clientX au clients abonnés quand il en envoie un
			sinon 
				afficher erreur
			
			fermeture du thread et du socket
		fin tant que
	fin tant que
fin
```
### 5/ Algorithme simplifié du client (peut être exécuté plusieurs fois tant qu'on n'atteind pas le nombre max de client connectés au serveur)

```
début
	ajout des librairies socket et pthread + autres librairies pour le fonctionnement du programme
	déclaration de la taille du buffer à 2048
	déclaration de la variable sub à 0
	déclaration du nombre max de client à 100
	saisie utilisateur de username client
	déclaration des paramètres du socket
		AF_INET <- IPv4
		SOCK_STREAM <- TCP
		PORT <- 4444
		IP <- 127.0.0.1 (loopback)
	si mauvaise connexion au serveur
		afficher erreur et quitter
	sinon
		continuer le programme
	fin si
	envoi de username client au serveur
	
	tant que 1
		quand le client envoi un message, on crée un thread pour cet envoi.
		quand le client reçoit un message, on crée un thread pour cette récéption.
		si buffer <- saisie de "exit"
			envoi de buffer au serveur
			arrêter le programme
		sinon si buffer <- saisie de "sub <username_clientX>"
			créer un thread de subscription
			sub <- +1
			recevoir les messages émis par username_clientX au clients abonnés quand il en envoie un
		sinon si buffer <- saisie de "unsub <username_clientX>"
			fermer le thread de subscription
			sub <- -1
			ne plus recevoir les messages émis par username_clientX aux clients abonnés quand il en envoie un
	fin tant que
fin
```

### 6- Sitographie

- https://broux.developpez.com/articles/c/sockets/






