
#include "server.h"
#include "game.h"

Server::Server(){
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
        if(this->flag == 0){
            new_socket = accept(server, (struct sockaddr *)&client_address, &client_len);
            if(new_socket <0)                   
            {
                std::cout<<"\n Error to accept client \n"<<std::endl;
            }else{
                std::cout<<"\n CLient accepted \n"<<std::endl;
            }
            while (true)
            {
                int len_request = read(new_socket, (char*)&buffer_reciever, sizeof(buffer_reciever));
                if(len_request==-1){
                    std::cout<<"Could not read message"<<std::endl;
                    break;
                }else if (len_request==0){//did not send 
                    std::cout<<"Socket closed"<<std::endl;
                    // close(new_socket);
                    break;
                }else if(((struct info_pack *)&buffer_reciever)->type_message == -1){
                    delete this->manager.memory;
                    close(new_socket);
                    this->flag = 1;
                    break;
                }else if(((struct info_pack *)&buffer_reciever)->type_message == 0){
                    write(new_socket,manager.manage_message((struct info_pack *)&buffer_reciever),sizeof(buffer_transmiter));
                }else if(((struct info_pack *)&buffer_reciever)->type_message == 1){
                    this->server_img = manager.getImage();
                    write(new_socket, server_img.data(), server_img.size());
                }
            }
        }else {
            std::cout<<"Close server"<<std::endl;
            close(server);
            break;
        }
    }
}