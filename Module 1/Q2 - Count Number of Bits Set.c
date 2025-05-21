#include <stdio.h>

int main()
{
    int num,dup,count=0;
    printf("Enter a number : ");
    scanf("%d",&num);
    dup=num;
    while(num){
        count+=(num&1);
        num>>=1;
    }
    printf("Number of bits set in %d is %d ",dup,count);
    return 0;
}
