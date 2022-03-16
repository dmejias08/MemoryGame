#include "client.h"

Client::Client(){
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(server_ip);
    serverAddress.sin_port = htons(PORT);
}
void Client::conexion(){
    char *buffer_trasmiter = new char[1024];
    buffer_trasmiter = "Hola server, soy cliente";
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if ( sock < 0)
    {
        std::cout<<"\n Socket creation error \n"<<std::endl;

        printf("\n Socket creation error \n");
        
    }else{
        std::cout<<"\n Socket connection succesfully \n"<<std::endl;
        //printf("Socket connection succesfully");
        
    }
      
    if (connect(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        std::cout<<"Connection failed"<<std::endl;
        //printf("\nConnection Failed \n");
    }

    write(sock,buffer_trasmiter, strlen(buffer_trasmiter));
    std::cout<<"Hello message sent\n"<<std::endl;
    //printf("Hello message sent\n");
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