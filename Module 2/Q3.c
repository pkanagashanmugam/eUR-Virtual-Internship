#include <stdio.h>
#include <stdlib.h>

#define SIZE_LIMIT 100
int queue[SIZE_LIMIT];
int rear=-1,front=-1;

void enqueue(int number){
    if(front ==-1)
        front=0;
    if(rear < SIZE_LIMIT-1)
        queue[++rear]=number;
    else
        printf("\nMAXIMUM SIZE OF QUEUE REACHED!!\n");
}

void display_queue(){
    int i;
    printf("\nFront --> ");
    for(i=front;i<rear;i++)
        printf("%d --> ",queue[i]);
    printf("%d <-- Rear\n",queue[i]);
}

void sort_queue(){
    int current_queue_size=rear-front+1;
    for(int i=0;i<current_queue_size;i++){
        for(int j=i+1;j<current_queue_size;j++){
            if(queue[i]>queue[j]){
                int temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
}

int main(){
    int option=1,queue_element;
    while(option==1){
        printf("Enter Element to add to the queue : ");
        scanf("%d",&queue_element);
        enqueue(queue_element);
        
        printf("\n1. Add Elements to the queue\n2. Exit : ");
        scanf("%d",&option);
    }
    printf("\nQueue before sorting : ");
    display_queue();

    sort_queue();
    
    printf("\nQueue after sorting : ");
    display_queue();
    return 0;
}
