#include "client.h"

Client::Client(){

}

/**
 * @brief It establishes a socket connection 
 * 
 * @param position_btn contanins the info of each button
 */
void Client::conexion(struct info_pack position_btn){

    buffer_transmiter = position_btn;
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
    std::cout<<"\n message sent \n"<<std::endl;
    len_response = read(sock, (struct info_pack*)&buffer_reciever, sizeof(buffer_reciever));
    /* Validation */
    if(len_response==-1){
        std::cout<<"Could not read message"<<std::endl;
    }else if (len_response==0){//did not send 
        std::cout<<"Empty message"<<std::endl;
    }else{
        /*info recieved from server*/
        this->points = ((struct info_pack*)&buffer_reciever)->points;
        this->current_player = ((struct info_pack*)&buffer_reciever)->current_player;
        this->response = ((struct info_pack*)&buffer_reciever)->id;
        this->card_type = ((struct info_pack*)&buffer_reciever)->card_type;
        this->player_points = ((struct info_pack*)&buffer_reciever)->player_points;
        this->winner = ((struct info_pack*)&buffer_reciever)->winner;
        this->punish_points = ((struct info_pack*)&buffer_reciever)->punish_points;
        this->punish_player = ((struct info_pack*)&buffer_reciever)->punish_player;
        this->size = ((struct info_pack*)&buffer_reciever)->size;
        if(this->response == 0){
            std::cout<<"Cliente: falta presionar una carta "<<std::endl;
        }else if(this->response== 1){
            std::cout<<"Cliente: son iguales "<<std::endl;
        }else {
            std::cout<<"Cliente: No son iguales "<<std::endl;

        }
    }
    
    close(sock);
}
/**
 * @brief it creates a socket connection in charge of sending a recieving image 
 * 
 * @param indicator a flag that indicates image 
 */
void Client::getImage(int indicator){

    this->client_img.erase();
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
    this->image_request.type_message = indicator;
    buffer_transmiter = this->image_request;
    /* send test sequences*/
    write(sock, (struct info_pack*)&buffer_transmiter, sizeof(buffer_transmiter));
    std::cout<<"[Client]size: "<<this->size<<std::endl;
    /*Creates char in which string base 64 is saves */
    char* temp = (char*)malloc(sizeof(char) * this->size);
    len_response = read(sock, temp, this->size);


    if (len_response == -1)
    {
        continue;
    }
    else if (len_response == 0){
        printf("[CLIENT]: client socket closed \n\n");
    }else{
        std::cout<<"Estoy leyendo imagen en client"<<std::endl;
        /*turns char to string base 64, that interface will use to get image*/
        for(int i = 0; i < len_response; i++){
            this->client_img.push_back(*(temp+i));
        }
    std::cout << "Control: " << client_img.size() << std::endl;
    }

    /* close the socket */
    close(sock);
}

