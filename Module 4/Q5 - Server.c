#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 65500

int palindrome(char *string){
        int string_length=strlen(string);
        for(int i=0;i<string_length/2;i++)
                if(string[i]!=string[string_length-i-1])
                        return 0;
        return 1;
}

int main(){
        struct sockaddr_in server_address,client_address;
        char buffer[BUFFER_SIZE];
        char message[BUFFER_SIZE];
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
        listen(server_fd,5);
        int new_socket = accept(server_fd,(struct sockaddr *)&client_address,&client_length);
        if(new_socket < 0){
                perror("Client Acceptance Failed");
                return 3;
        }

        read(new_socket,buffer,BUFFER_SIZE);
        printf("\nString from Client is %s\n",buffer);

        if(palindrome(buffer))
                strcpy(message,"Palindromic");
        else
                strcpy(message,"Non Palindromic");

        send(new_socket,message,strlen(message),0);
        printf("Message sent to Client\n");

        close(new_socket);
        close(server_fd);

        return 0;
}
