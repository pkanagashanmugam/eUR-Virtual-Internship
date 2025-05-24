#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define PORT 65500

int main(){
        struct sockaddr_in server_address,client_address;
        char buffer[BUFFER_SIZE];
        char *message="Message Received. Hello from Server using UDP protocol!";
        socklen_t client_length=sizeof(client_address);
        bzero(&server_address,sizeof(server_address));

        int sockfd = socket(AF_INET,SOCK_DGRAM,0);
        if(sockfd < 0){
                perror("Socket Creation Error");
                return 1;
        }
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);
        server_address.sin_addr.s_addr = INADDR_ANY;

        int binder=bind(sockfd,(struct sockaddr *)&server_address,sizeof(server_address));
        if( binder < 0){
                perror("Socket Binding Error");
                return 2;
        }

        int client=recvfrom(sockfd,buffer,BUFFER_SIZE,0,(struct sockaddr *)&client_address,&client_length);
        buffer[client] = '\0';
        printf("Message from Client : %s\n",buffer);

        sendto(sockfd,message,strlen(message),0,(struct sockaddr *)&client_address,client_length);
        printf("Message sent to Client\n");

        close(sockfd);

        return 0;
}
