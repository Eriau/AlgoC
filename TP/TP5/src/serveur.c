/*
 * SPDX-FileCopyrightText: 2020 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "calcule.h"

#include "serveur.h"

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data) {
  int data_size = write (client_socket_fd, (void *) data, strlen(data));
      
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd) {
  struct sockaddr_in client_addr;
  char data[1024];

  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
  
  /*
   * extraire le code des données envoyées par le client. 
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf ("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);

  //5.4
  char message[100];
  printf("Entrez un message à envoyer au client : (100 car max) :\n");
  fgets(message,100,stdin); // stdin car on recupère les infos du clavier et non d'un fichier
  strcpy(data, "Message du serveur : ");
  strcat(data, message);
  renvoie_message(client_socket_fd, data);

  //fermer le socket 
  close(socketfd);
}

int recois_numeros_calcule(int socketfd){
    struct sockaddr_in client_addr;
    char data[1024];

    int client_addr_len = sizeof(client_addr);

    // nouvelle connection de client    printf("%s \n", demande);

    int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_socket_fd < 0 ) {
        perror("accept");
        return(EXIT_FAILURE);
    }

    // la réinitialisation de l'ensemble des données
    memset(data, 0, sizeof(data));

    //lecture de données envoyées par un client
    int data_size = read (client_socket_fd, (void *) data, sizeof(data));

    if (data_size < 0) {
        perror("erreur lecture");
        return(EXIT_FAILURE);
    }

    // On veut extraire les infos du calcul afin de pouvoir le faire
    printf ("Calcul reçu: %s\n", data);
    // On recup les chiffres et l'opération (faudrait faire un truc qui récup qq soit la manière d'écriture...)
    int i = 0;
    int a = 0;
    char ope = data[0];
    int b = 0;
    char *throughData;
    throughData = malloc(256);
    while(data[i]!='\0'){
      if(data[i] >= '0' && data[i] <= '9'){ // On check si c'est un nombre
        throughData[strlen(throughData)] = data[i]; // On ajoute à notre chaine tant que l'on ne rencontre pas autre chose qu'un chiffre
      }else{
        if(a==0){
          a = atoi(throughData);
        }else{
          b = atoi(throughData);
        }
        memset(throughData, 0, sizeof(throughData));
      }
      i++;
    }
    
    char str[20];

    int result = calcul(a, ope, b);

    sprintf(str, "%d", result);

    strcpy(data, "Resultat: ");
    strcat(data, str);
    

    renvoie_message(client_socket_fd, data);


    /*//Si le message commence par le mot: 'message:'
    if (strcmp(code, "message:") == 0) {strcpy(temp,"");
        renvoie_message(client_socket_fd, data);
    }*/

    //fermer le socket
    close(socketfd);
}



int main() {

  int socketfd;
  int bind_status;
  int client_addr_len;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (bind_status < 0 ) {
    perror("bind");
    return(EXIT_FAILURE);
  }
 
  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  //Lire et répondre au client
  recois_numeros_calcule(socketfd);

  return 0;
}
