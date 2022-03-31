#include "client.h"

Client::Client(){
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(server_ip);
    serverAddress.sin_port = htons(PORT);
}


void Client::conexion(char message[1024]){
    char *buffer_transmiter = new char[1024];
    buffer_transmiter = message;
    // buffer_trasmiter = "Hola server, soy cliente";
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if ( sock < 0)
    {
        std::cout<<"\n Socket creation error \n"<<std::endl; 
    }else{
        std::cout<<"\n Socket connection succesfully \n"<<std::endl;
        
    }
      
    if (connect(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        std::cout<<"\n Connection failed \n"<<std::endl;
    }else{
        std::cout<<"\n Connection to server succesfully \n"<<std::endl;
    }
    
    write(sock,buffer_transmiter, strlen(buffer_transmiter));
    // write(sock,code, strlen(code));
    std::cout<<"\n message sent \n"<<std::endl;
    len_response = read(sock, buffer_reciever, sizeof(buffer_reciever));
    if(len_response==-1){
        std::cout<<"Could not read message"<<std::endl;
    }else if (len_response==0){//did not send 
        std::cout<<"Empty message"<<std::endl;
    }else{
        std::cout<<buffer_reciever<<std::endl;
    }
    
    close(sock);
}