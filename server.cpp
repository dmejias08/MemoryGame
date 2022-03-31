
#include "server.h"
#include "game.h"
Server::Server(){
    char *buffer_trasmiter= new char[1024];
    // buffer_trasmiter = "Hola Dario, soy server";
    
    server= socket(AF_INET, SOCK_STREAM, 0);
    if(server < 0){
        std::cout<<"\n Error initializing server \n"<<std::endl;
    }else{
        std::cout<<"\n Initialize server succesfullly \n"<<std::endl;
    }

    //Cleaning struct
    memset(&server_address,0, sizeof(server_len));
    //Initialize struct 
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons( PORT );
       
    //Bind the socket to the local port 
    if (bind(server, (struct sockaddr *)&server_address, sizeof(server_address))<0)
    {
        std::cout<<"\n Bind error \n"<<std::endl;
    }else{
        std::cout<<"\n Bind succesfully \n"<<std::endl;
    }
    
    //Listen request from client
    if (listen(server, 3) < 0)
    {
        std::cout<<"\n Error listening \n"<<std::endl;
    }else{
        std::cout<<"\n Started to listen \n"<<std::endl;
    }


    //Acept connections it extracts the first connection request
    //on the queue
    while (true)
    {
        new_socket = accept(server, (struct sockaddr *)&client_address, &client_len);
        if(new_socket <0)                   
        {
            std::cout<<"\n Error to accept client \n"<<std::endl;
        }else{
            std::cout<<"\n CLient accepted \n"<<std::endl;
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
                // write(new_socket,buffer_trasmiter,strlen(buffer_trasmiter));
                std::cout<<"SERVER"<<buffer_reciever<<std::endl;
                // handeling_message(buffer_reciever);
                buffer_trasmiter = handeling_message(buffer_reciever);
                write(new_socket,buffer_trasmiter,strlen(buffer_trasmiter));
                // buffer_trasmiter =funtion that retruns a message from handeling message 
            }
        }
    }
}
char* Server::handeling_message(char message[1024]){
    std::cout<<"Mensaje: "<<message<<" en handeling message"<<std::endl;
    int pos1;
    int pos2;
    //position arrives 
    int i;
    sscanf(message, "%d", i);
    std::cout<<"estoy en sever pos es "<<i<<std::endl;
    
    if(pos1 == 0){
        pos1 = i;
    }else if(pos2 == 0){
        pos2 = i;
    }else{

        char *response = new char[1024];
        response =(char*)this->game.check_equals(pos1,pos2); ;
        return response;
    }

    

   
   
   
    

// this method is going to read the message and redirect it to the method it needs to go
}
