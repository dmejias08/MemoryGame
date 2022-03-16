
#include "server.h"

Server::Server(){
        server= socket(AF_INET, SOCK_STREAM, 0);
    if(server < 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }else{
        std::cout<<"Initialize server succesfullly"<<std::endl;
        //printf("Initialize server succesfullly");
    }
    //Cleaning struct
    memset(&server_address,0, sizeof(server_len));
    //Initialize struct 
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons( PORT );
       
    //Bind the socket to the local port 
    if (bind(server, (struct sockaddr *)&server_address, 
                                 sizeof(server_address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }else{
        std::cout<<"Bind succesfully"<<std::endl;
    }

    //Listen request from client
    if (listen(server, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }else{
        std::cout<<"Started to listen"<<std::endl;
        //printf("Started to listen");
    }


    //Acept connections it extracts the first connection request
    //on the queue
    while (true)
    {
        new_socket = accept(server, (struct sockaddr *)&client_address, &client_len);
        if(new_socket <0)                   
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }else{
            std::cout<<"CLient accepted"<<std::endl;
        }
    

        while (true)
        {
            int len_request = read(new_socket, buffer_reciever, sizeof(buffer_reciever));
            if(len_request==-1){
                std::cout<<"Could not read message"<<std::endl;
            }else if (len_request==0){//did not send 
                std::cout<<"Socket closed"<<std::endl;
                close(new_socket);
                break;
            }else{
                write(new_socket,buffer_trasmiter,strlen(buffer_trasmiter));
                std::cout<<"SERVER"<<buffer_trasmiter<<std::endl;
            }
        }
    }
}
void Server::handeling_message(char[]){
// this method is going to read the message and redirect it to the method it needs to go
}
