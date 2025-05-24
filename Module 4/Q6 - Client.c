#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define PORT 65500

int main(){
        struct sockaddr_in server_address;
        char buffer[BUFFER_SIZE],message[BUFFER_SIZE];
        //char *message="Hello from Client using UDP protocol!";
        socklen_t client_length=sizeof(server_address);
        bzero(&server_address,sizeof(server_address));

        int sockfd = socket(AF_INET,SOCK_DGRAM,0);
        if(sockfd < 0){
                perror("Socket Creation Error");
                return 1;
        }
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);
        server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

        printf("Enter message to server : ");
        scanf("%[^\n]s",message);

        sendto(sockfd,message,strlen(message),0,(struct sockaddr *)&server_address,client_length);
        printf("Message sent to Server\n");

        int server=recvfrom(sockfd,buffer,BUFFER_SIZE,0,NULL,NULL);
        printf("Message from Server : %s\n",buffer);

        close(sockfd);

        return 0;
}
