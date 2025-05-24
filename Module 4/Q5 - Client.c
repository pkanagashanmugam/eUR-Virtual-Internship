#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 65500
#define BUFFER_SIZE 1024

int main(){
        struct sockaddr_in server_address;
        char buffer[BUFFER_SIZE];
        char message[BUFFER_SIZE];

        printf("Enter string : ");
        scanf("%[^\n]",message);

        memset(buffer, 0, BUFFER_SIZE);
        int sock = socket(AF_INET,SOCK_STREAM,0);
        if( sock < 0){
                perror("Socket Creation Failed");
                return 1;
        }
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);

        if(inet_pton(AF_INET,"127.0.0.1",&server_address.sin_addr) <= 0){
                perror("Address not supported");
                return 2;
        }
        if(connect(sock,(struct sockaddr *)&server_address,sizeof(server_address)) <0){
                perror("Connection to Server Failed!");
                return 3;
        }
        send(sock,message,strlen(message),0);
        printf("Message sent to server\n");

        read(sock,buffer,BUFFER_SIZE);
        printf("%s is a %s string",message,buffer);

        close(sock);

        return 0;
}
