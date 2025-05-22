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
    int option=1,rotate,list_length=0;
    while(option==1){
        //Dynamically creating memory for the node
        node *data_node=(node *)malloc(sizeof(node));
        printf("Enter the number to be added to the list : ");
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
    //Getting value for number of rotations 
    printf("\nEnter value for list rotation : ");
    scanf("%d",&rotate);
    if(rotate!=0 && rotate!=list_length){
        //Wrapping number of rotations to the length of the linked list
        rotate%=list_length;
        node* ptr=head;
        
        for(int i=0;i<rotate;i++)
            ptr=ptr->next;
        //Redefining pointers 
        node *new_tail=ptr->previous;
        ptr->previous->next=NULL;//Assigns the next new tail to NULL
        ptr->previous=NULL;//Points the previous of new head to NULL
        tail->next=head;//Points next of current tail to current head
        head->previous=tail;//Points previous of current head to current tail
        head=ptr;//Assigns new Head
        tail=new_tail;//Assigns new Tail
    }else
        printf("\nNo Rotation required!\n");
    printf("\nList after Rotation: \n");
    print_list();
    printf("\n\nNew Head has the value %d\nNew Tail has the value %d",head->data,tail->data);
    return 0;
}
