#include "memory_managment.h"
#include "memory_managment.cpp"

int main(){

    //Archivo de pruebas
    Memory_managment *memory = new Memory_managment();
    // memory->set_card_to_file(1,1,1,0);
    // memory->set_card_to_file(1,2,2,0);
    // memory->set_card_to_file(1,3,3,0);
    // memory->set_card_to_file(1,4,3,0);
    // memory->get_card_from_file(1,2);
    // memory->get_card_from_file(1,4);
    // memory->set_card_to_file(1,2,2,1);
    // memory->get_card_from_file(1,2);
    // memory->get_card_from_file(1,3);
    // memory->get_card_from_file(1,2);
    // memory->get_card_from_file(1,1);
    // memory->get_card_from_file(1,2);
    // memory->get_card_from_file(1,3);

    memory->create_file();
    memory->generate_vector();
    memory->print_vector();

    cout<<"****************************************"<<endl;
    memory->get_card_from_file(1,4);
    memory->get_card_from_file(2,3);
    cout<<"****************************************"<<endl;
    memory->get_card(2,3);
    cout<<"****************************************"<<endl;
    memory->get_card(7,4);
    cout<<"****************************************"<<endl;
    memory->print_file();
    delete memory;
} 