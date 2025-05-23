#include <stdio.h>
#include <string.h>

#define SIZE_LIMIT 100

char stack[SIZE_LIMIT];
int top=-1;

void push(char character){
    if(top == SIZE_LIMIT-1){
        printf("\nStack Overflow");
        return;
    }
    stack[++top]=character;
}

char pop(){
    if(top == -1){
        printf("\nStack Underflow");
        return '\0';
    }
    return stack[top--];
}

int main(){
    char input[SIZE_LIMIT];
    printf("Enter the string : ");
    scanf("%[^\n]s",input);
    
    int string_length=strlen(input),i;
    for(i=0;i<string_length;i++)
        push(input[i]);
    char reversed_string[string_length+1];
    
    for(i=0;i<string_length;i++)
        reversed_string[i]=pop();
    reversed_string[i]='\0';
    
    printf("Reversed String is : %s",reversed_string);
    return 0;
}
