#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <libconfig.h>

#include "../headers/clientcxnmanager.h"
#include "../headers/config.h"
#include "../headers/game.h"

//Interface graphique
#include <gtk/gtk.h>
#include "../headers/interface.h"

// Déclaration des variables d'interface GTK
// GtkWidget * MainWindow = NULL;

GameData gameData;
PlayerGameSettings cfgPlayer;

void *threadProcess(void * ptr) {
    ClientConfig cfgClient = initCfg();

    char buffer_in[BUFFERSIZE];
    int sockfd = *((int *) ptr);
    int len;

    //Envoi de la configuration client au serveur
    write(sockfd, &cfgClient, sizeof(cfgClient));
    //Lecture de la configuration initiale du joueur
    read(sockfd, &gameData, sizeof(cfgPlayer));
    printf("%d", gameData.p1.balance);

    // if(cfgClient.idClient == gameData.p1.idClient)
    // {
    // }
    // else if (cfgClient.idClient == gameData.p2.idClient)
    // {
    // }

    while ((len = read(sockfd, &gameData, sizeof(cfgPlayer))) > 0);

    close(sockfd);
    printf("client pthread ended, len=%d\n", len);
}

int open_connection(ClientConfig cfgClient) {
    int sockfd;
    struct sockaddr_in serverAddr;

    // Create the socket. 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //Configure settings of the server address
    // Address family is Internet 
    serverAddr.sin_family = AF_INET;
    //Set port number, using htons function 
    serverAddr.sin_port = htons(cfgClient.serverPort);
    //Set IP address to localhost
    serverAddr.sin_addr.s_addr = inet_addr(cfgClient.serverIP);

    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    //Connect the socket to the server using the address
    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof (serverAddr)) != 0) {
        printf("Fail to connect to server");
        exit(-1);
    };

    return sockfd;
}
