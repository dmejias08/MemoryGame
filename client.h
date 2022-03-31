#ifndef client_h
#define client_h

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
#define PORT 8080
#define server_ip "192.168.0.13"



class Client{
    private:
    int sock;
    int len_response;
    struct sockaddr_in serverAddress;
    char buffer_reciever[1024];
    
    public:
    Client();
    void conexion(char message[1024], int code);
    // void handeling_message(char message[1024]);
    // char* message();
};

#endif