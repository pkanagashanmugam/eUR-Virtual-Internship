#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 65500


int main(){
        struct sockaddr_in server_address,client_address;
        char buffer[BUFFER_SIZE];
        const char *message = "Hello from Server!";
        socklen_t address_length = sizeof(server_address),client_length=sizeof(client_address);

        int server_fd = socket(AF_INET,SOCK_STREAM,0);
        if(server_fd == 0){
                perror("Socket Creation Failed");
                return 1;
        }
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_port = htons(PORT);

        int binder = bind(server_fd,(struct sockaddr *)&server_address,sizeof(server_address));
        if(binder < 0){
                perror("Socker Binding Failed");
                return 2;
        }
        printf("\n Server Listening to Port %d",PORT);
        listen(server_fd,5);
        int new_socket = accept(server_fd,(struct sockaddr *)&client_address,&client_length);
        if(new_socket < 0){
                perror("Client Acceptance Failed");
                return 3;
        }

        read(new_socket,buffer,BUFFER_SIZE);
        printf("\nMessage from Client is %s\n",buffer);

        send(new_socket,message,strlen(message),0);
        printf("Hello message sent to client\n");

        close(new_socket);
        close(server_fd);

        return 0;
}
