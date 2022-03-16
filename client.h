#ifndef server_h
#define server_h

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
#define server_ip "192.168.0.10"



class Client{
    private:
    int sock;
    int len_response;
    struct sockaddr_in serverAddress;
    char buffer_reciever[1024];
    
    public:
    Client();
    void conexion();
};

#endif