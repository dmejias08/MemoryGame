#ifndef card_h
#define card_h

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>

class Card{

    private:
    std::string name, img, id, status;

    public:
    Card(std::string id, std::string name, std::string img, std::string status);//create a card object
     void print();

};

#endif 
