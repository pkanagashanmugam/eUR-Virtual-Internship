#include <stdio.h>
#include <pthread.h>

int global_value=100;
pthread_mutex_t mutex;

void *add(void *args){
    int number=*(int *)args;
    pthread_mutex_lock(&mutex);
    global_value+=number;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *subtract(void *args){
    int number=*(int *)args;
    pthread_mutex_lock(&mutex);
    global_value-=number;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *multiply(void *args){
    int number=*(int *)args;
    pthread_mutex_lock(&mutex);
    global_value*=number;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *divide(void *args){
    int number=*(int *)args;
    pthread_mutex_lock(&mutex);
    global_value/=number;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(){
    pthread_t thread1,thread2,thread3,thread4;
    int base;
    printf("Enter base number to perform arithmetic calculations : ");
    scanf("%d",&base);
    
    pthread_create(&thread1,NULL,add,(void *)&base);
    pthread_join(thread1,NULL);
    printf("Global value after addition : %d\n",global_value);
    
    pthread_create(&thread3,NULL,multiply,(void *)&base);
    pthread_join(thread1,NULL);
    printf("Global value after multiplication : %d\n",global_value);
    
    pthread_create(&thread4,NULL,divide,(void *)&base);
    pthread_join(thread1,NULL);
    printf("Global value after division : %d\n",global_value);
    
    pthread_create(&thread2,NULL,subtract,(void *)&base);
    pthread_join(thread1,NULL);
    printf("Global value after subtraction : %d\n",global_value);
    
    return 0;
}
