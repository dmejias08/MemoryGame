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
using namespace std;



class Card{

    private:
    int i, j, type, status;
    string img;
    //unsigned char byte_array[1000] = {0};

    public:
    Card(int i , int j , int type , int status);
    void get_image(int type);
    void print();

};

#endif 
