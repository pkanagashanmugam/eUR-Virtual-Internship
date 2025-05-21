#include <stdio.h>

void swap(int *ptra,int *ptrb){
    *ptra+=*ptrb;
    *ptrb=*ptra-*ptrb;
    *ptra-=*ptrb;
}

int main()
{
    int a,b;
    void (*func_ptr)(int *, int *) = &swap;
    printf("Enter two nubmers : ");
    scanf("%d %d",&a,&b);
    printf("Before Swap a=%d b=%d\n",a,b);
    func_ptr(&a,&b);
    printf("After Swap a=%d b=%d",a,b);
    return 0;
}
