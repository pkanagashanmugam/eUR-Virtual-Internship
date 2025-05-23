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

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nELEMENT CANNOT BE REMOVED FROM EMPTY QUEUE\n");
        front = -1;
        rear = -1;
        return;
    }
    printf("\nElement deleted is %d", queue[front]);
    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void display_queue(){
    if(front ==-1){
        printf("\nQueue is empty\n");
        return;
    }
    int i;
    printf("\nFront --> ");
    for(i=front;i<rear;i++)
        printf("%d --> ",queue[i]);
    printf("%d <-- Rear\n",queue[i]);
}

void sort_queue(){
    int current_queue_size=rear-front+1;
    for(int i=front;i<rear;i++){
        for(int j=i+1;j<rear;j++){
            if(queue[i]>queue[j]){
                int temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
}

int main(){
    int option,queue_element;
    printf("\n1. Add Elements to the Queue\n2. Remove Element from Queue\n3. Display the Queue\n4. Display length of the Queue : ");
    scanf("%d",&option);
    while(option<5 && option>0){
        switch(option){
            case 1:
                printf("Enter Element to add to the queue : ");
                scanf("%d",&queue_element);
                enqueue(queue_element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display_queue();
                break;
            case 4:
                int size=(front!=-1)?rear-front+1:0;
                printf("\nCurrent size of the Queue is %d\n",size);
                break;
            default:
                printf("Enter valid choice");
        
        }
        printf("\n1. Add Elements to the Queue\n2. Remove Element from Queue\n3. Display the Queue\n4. Display length of the Queue\n5. Exit : ");
        scanf("%d",&option);
    }
    return 0;
}
