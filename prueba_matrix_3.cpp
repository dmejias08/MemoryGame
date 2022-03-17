#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define N 5
#include "card.h"
#include "card.cpp"

using namespace std;
int main(){
vector<Card> vector_card;

vector_card.push_back(Card("1","perro", "perro.png","0"));
vector_card.push_back(Card("1","perro", "perro.png","0"));
for (int i = 0; i<=1; i++){
    vector_card[i].print();
}
// Card arr;
// Card* arr = (Card*)malloc(sizeof(Card) * N);

// arr[0] = Card(1, "perro" , "perro.png", 0);
// arr[1] = Card(1, "perro" , "perro.png", 0);
// arr[2] = Card(1, "perro" , "perro.png", 0);
// arr[3] = Card(1, "perro" , "perro.png", 0);
// arr[4] = Card(1, "perro" , "perro.png", 0);
// arr[1].print();
// arr[0].print();
// arr[2].print();
}


