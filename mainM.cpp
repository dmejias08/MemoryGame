#include "memory_managment.h"
#include "memory_managment.cpp"

int main(){
    Memory_managment *memory = new Memory_managment();
    // memory->set_card_to_file(1,1,1,0);
    // memory->set_card_to_file(1,2,2,0);
    // memory->set_card_to_file(1,3,2,0);
    // memory->set_card_to_file(1,4,3,0);
    // memory->get_card_from_file(1,2);
    // memory->get_card_from_file(1,4);
    // memory->set_card_to_file(1,2,2,1);
    // memory->get_card_from_file(1,2);
    memory->create_file();
    // memory->get_card_from_file(1,1);
    // memory->get_card_from_file(1,2);
    // memory->get_card_from_file(1,3);
    memory->generate_vector();
    delete memory;
}