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
    std::vector<Card*> vector_card;

    public:
    // void get_card(int i, int j);
    void generateVector();
    Card* get_from_csv(std::string id); // if there is not card in matrix get it from the csv or to create a matrix


};

#endif 

