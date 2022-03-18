#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;
fstream archive_memory;

struct simple_card{
    int i;
    int j;
    int status;
    string name;
};

// void disk_memory(){
//     archive_memory = fstream("archive.txt", ios::in | ios::out | ios::binary);
//     if (!archive_memory.good()){
//         ofstream newFile("archive_memory.txt");
//         newFile.close();
//         archive_memory = fstream("archive_memory.txt", ios::in | ios::out | ios::binary);
//     }
// }

int main(){
    // disk_memory;
    archive_memory.open("archive.txt", ios::in | ios::out | ios::binary);
    simple_card card1;
    simple_card card2;
    card1.i = 1;
    card1.j = 1;
    card1.status = 0;
    card1.name = "Gato";
    card2.i = 1;
    card2.j = 2;
    card2.status = 0;
    card2.name = "Perro";
    archive_memory.write((char*)&card1, sizeof(simple_card));
    archive_memory.write((char*)&card2, sizeof(simple_card));
    archive_memory.seekg(sizeof(simple_card),ios::beg);
    char *buffer = (char*) malloc(sizeof(simple_card));
    archive_memory.read(buffer, sizeof(simple_card));
    simple_card* card3 = (simple_card*) buffer;
    cout<<card3->i<<" "<<card3->j<<" "<<card3->name<<endl;
    free(buffer);
    archive_memory.close();
}