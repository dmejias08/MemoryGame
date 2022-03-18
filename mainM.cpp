#include "memory_managment.h"
#include "memory_managment.cpp"

int main(){
    Memory_managment *memory = new Memory_managment();
    memory->setCard(1,1,1,0);
    memory->setCard(1,2,2,0);
    memory->setCard(1,3,2,0);
    memory->setCard(1,4,3,0);
    memory->getCard(1,2);
    memory->getCard(1,4);
    memory->setCard(1,2,2,1);
    memory->getCard(1,2);
}