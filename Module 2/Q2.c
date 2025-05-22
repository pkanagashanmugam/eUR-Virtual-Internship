#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* previous;
};
typedef struct node node;

node *head=NULL;
node *tail=NULL;

void print_list(){
    printf("\nLinked List :\n");
    node* ptr=tail;
    while(ptr!=NULL){
        printf("%d-->",ptr->data);
        ptr=ptr->previous;
    }
    printf("NULL");
}

int main(){
    int option=1,rotate;
    while(option==1){
        node *data_node=(node *)malloc(sizeof(node));
        printf("Enter the number to be added to the list : ");
        scanf("%d",&data_node->data);
        data_node->next=NULL;
        data_node->previous=NULL;
        
        if(head==NULL){
            head=data_node;
            tail=data_node;
        }
        else{
            node* ptr=head;
            while(ptr->next!=NULL)  
                ptr=ptr->next;
            ptr->next=data_node;
            data_node->previous=ptr;
            tail=data_node;
        }
        printf("\n1. Add Elements to list\n2. Exit\n");
        scanf("%d",&option);
    }
    
    print_list();
    
    printf("Enter value for list rotation : ");
    scanf("%d",&rotate);
    
    printf("\nList after Rotation: \n");
    print_list();
    return 0;
}
