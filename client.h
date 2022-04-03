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
#define server_ip "192.168.0.40"

struct info_pack
{
    int id;
    int type_message;
};


class Client{
    private:
    int sock;
    int len_response;
    struct sockaddr_in serverAddress;
    struct info_pack buffer_reciever;
    struct info_pack buffer_transmiter;

    // char buffer_reciever[1024];
    
    public:
    int response;
    struct info_pack request;
    Client();
    void conexion(struct info_pack position_btn);
};

#endif