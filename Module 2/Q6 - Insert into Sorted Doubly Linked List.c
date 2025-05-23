#include <stdio.h>
#include <stdlib.h>
//Defining the structure
struct node{
    int data;
    struct node* next;
    struct node* previous;
};
typedef struct node node;
//Globally defining head and tail
node *head=NULL;
node *tail=NULL;
//Function to print the linked list
void print_list(){
    printf("\nLinked List :\n");
    node* ptr=head;
    while(ptr!=NULL){
        printf("%d-->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

int main(){
    int option=1,new_number,list_length=0,valid_position=-1;
    while(option==1){
        print_list();
        //Dynamically creating memory for the node
        node *data_node=(node *)malloc(sizeof(node));
        printf("\nEnter the number to be added to the sorted list : ");
        scanf("%d",&data_node->data);
        data_node->next=NULL;
        data_node->previous=NULL;
        //Inserting the node at the appropriate place
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
        list_length++;
        printf("\n1. Add Elements to list\n2. Exit : ");
        scanf("%d",&option);
    }
    
    print_list();
    printf("\nEnter element to be added to the sorted linked list : ");
    scanf("%d",&new_number);
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=new_number;
    
    node *ptr=head;
    while(ptr->next!=NULL){
        if(ptr->data<=new_number && new_number<=ptr->next->data){
            valid_position=1;
            break;
        }
        ptr=ptr->next;
    }
    if(valid_position==1){
        ptr->next->previous=new_node;
        new_node->next=ptr->next;
        ptr->next=new_node;
        new_node->previous=ptr;
    }else{
        if(head->data>new_number){
            head->previous=new_node;
            new_node->next=head;
            new_node->previous=NULL;
            head=new_node;
        }
        else{
            tail->next=new_node;
            new_node->previous=tail;
            new_node->next=NULL;
            tail=new_node;
        }
    }
    
    printf("\n\nList after Element Insertion:");
    print_list();
    return 0;
}
