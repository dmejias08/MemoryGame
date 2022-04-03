#ifndef memory_managment_h
#define memory_managment_h

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include "card.h"
#include "card.cpp"


class Memory_managment{

    private:
    std::vector<Card> vector_card;
    

    public:
    Memory_managment();
    Card get_card(int i, int j);
    Card replace(int i, int j);
    void generate_vector();
    void create_file();
    Card get_card_from_file(int i, int j); // if there is not card in matrix get it from the csv or to create a matrix
    void set_card_to_file(int i, int j, int type, int status);
    void print_vector();
    void shuffle();
    void print_file();

};

#endif 

