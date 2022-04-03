#include "client.h"

Client::Client(){

}


void Client::conexion(struct info_pack position_btn){

    buffer_transmiter = position_btn;
    // char *buffer_transmiter = new char[1024];
    // buffer_transmiter = message;
    // buffer_trasmiter = "Hola server, soy cliente";
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if ( sock < 0)
    {
        std::cout<<"\n Socket creation error \n"<<std::endl; 
    }else{
        std::cout<<"\n Socket connection succesfully \n"<<std::endl;
        
    }
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(server_ip);
    serverAddress.sin_port = htons(PORT);
      
    if (connect(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        std::cout<<"\n Connection failed \n"<<std::endl;
    }else{
        std::cout<<"\n Connection to server succesfully \n"<<std::endl;
    }
    
    write(sock, (struct info_pack*)&buffer_transmiter, sizeof(buffer_transmiter));
    // write(sock,code, strlen(code));
    std::cout<<"\n message sent \n"<<std::endl;
    len_response = read(sock, (struct info_pack*)&buffer_reciever, sizeof(buffer_reciever));
    /* Validation */
    if(len_response==-1){
        std::cout<<"Could not read message"<<std::endl;
    }else if (len_response==0){//did not send 
        std::cout<<"Empty message"<<std::endl;
    }else{
        response = ((struct info_pack*)&buffer_reciever)->id;
        if(response == 0){
            std::cout<<"Cliente: falta presionar una carta "<<std::endl;
        }else if(response == 1){
            std::cout<<"Cliente: son iguales "<<std::endl;
        }else{
            std::cout<<"Cliente: No son iguales "<<std::endl;

        }
    }
    
    close(sock);
}