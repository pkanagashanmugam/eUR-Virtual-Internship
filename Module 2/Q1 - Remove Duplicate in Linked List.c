#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node* next;
};

typedef struct node node;
node* head=NULL;

void print_list(){
    printf("\nLinked List :\n");
        node* ptr = head;
		while(ptr!=NULL){
			printf("%d-->",ptr->data);
		    ptr=ptr->next;
		}
        printf("NULL\n");
}
int main(){
        int option=1,num;
        while(option==1){
        	node* temp=(node*)malloc(sizeof(node));
            printf("\nEnter number to add to the sorted linked list : ");
        	scanf("%d",&temp->data); 
        	temp->next = NULL;
        	if(head==NULL)	
        		head = temp;
        	else{
        		struct node* ptr = head;
        		while(ptr->next!=NULL)
        			ptr = ptr->next;
        		ptr->next = temp; 
        	}
            printf("\n1. Continue Adding Numbers\n2. Exit : ");
            scanf("%d",&option);
        }
        
        print_list();
        int dup=-1;
        
        node* ptr = head;
		while(ptr->next!=NULL){
			if(ptr->data==ptr->next->data){
			    dup=ptr->data;
			    ptr->next=ptr->next->next;
			}
		    ptr=ptr->next;
            if(ptr==NULL)
                break;
		}
        if(dup==-1)
            printf("\nThere are no duplicate elements");
        else{
            printf("\nDuplicate element %d has been removed\nList after removal :\n",dup);
            print_list();
        }
        

}
