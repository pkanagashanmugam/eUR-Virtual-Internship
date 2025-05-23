#include <stdio.h>
#include <string.h>

#define SIZE_LIMIT 100

int array_1[SIZE_LIMIT], array_2[SIZE_LIMIT];
int top_1=-1,top_2=-1;

void push_1(int number){
    if(top_1<SIZE_LIMIT)
        array_1[++top_1]=number;
    else
        printf("\nStack Overflow");
}

void push_2(int number){
    if(top_2<SIZE_LIMIT)
        array_2[++top_2]=number;
    else
        printf("\nStack Overflow");
}

int pop_2(){
    if(top_2>-1)
        return array_1[top_2--];
    printf("\nStack Underflow");
    return 1;
}

int isSubset(){
    int subset_size=top_2+1,count=0;
    while(top_2!=-1){
        int current=pop_2();
        for(int i=0;i<=top_1;i++){
            if(current == array_1[i])
                count++;
        }
    }
    if (count==subset_size)return 1; else return 0;
}

int main(){
    int option=1,stack_element;
    printf("Enter elements of Stack 1 :\n");
    while(option==1){
        printf("Enter number to add to Stack 1 : ");
        scanf("%d",&stack_element);
        push_1(stack_element);
        
        printf("Enter 1 to continue adding numbers : ");
        scanf("%d",&option);
    }
    option=1;
    printf("\nEnter elements of Stack 2 :\n");
    while(option==1){
        printf("Enter number to add to Stack 2 : ");
        scanf("%d",&stack_element);
        push_2(stack_element);
        printf("Enter 1 to continue adding numbers : ");
        scanf("%d",&option);
    }
    
    printf("\nStack 1 :\n");
    for(int i=0;i<=top_1;i++)
        printf("%d ",array_1[i]);
    printf("\nStack 2 :\n");
    for(int i=0;i<=top_2;i++)
        printf("%d ",array_2[i]);
        
    if(isSubset())
        printf("\nArray 2 is a subset of Array 1");
    else
        printf("\nArray 2 is not a subset of Array 1");
    return 0;
}
