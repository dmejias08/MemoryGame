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


class Server{
    private: 
    int server, new_socket;
    char value_read;
    struct sockaddr_in server_address, client_address;
    unsigned int client_len;
    int opt;
    int server_len;
    char buffer_reciever[1024];


    public:
    Server();
    void handeling_message(char message[1024]);
};
#endif