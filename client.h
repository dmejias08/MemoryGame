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
#define server_ip "192.168.100.49"

struct info_pack
{
    int size;
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

    
    public:
    std::string client_img;
    int size;
    int punish_points;
    int winner;
    int response;
    int card_type;
    int current_player;
    int points;
    int player_points;
    int punish_player;
    struct info_pack request;
    struct info_pack image_request;
    Client();
    void conexion(struct info_pack position_btn);
    void getImage(int indicator);
};

#endif