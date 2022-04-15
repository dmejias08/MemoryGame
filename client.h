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
#define PORT 8000
#define server_ip "192.168.0.40"

struct info_pack
{
    int id;
    int type_message;
    int card_type;
    int current_player;
    int points;
    int player_points;
    int winner;
    int punish_points;
    int punish_player;
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
    int punish_points;
    int winner;
    int response;
    int card_type;
    int current_player;
    int points;
    int player_points;
    int punish_player;
    // char img; 
    struct info_pack request;
    Client();
    void conexion(struct info_pack position_btn);
};

#endif