#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 5
typedef int itype;


typedef struct queue
{
    itype a[MAX];
    int front,rear;
}queue;

void initialize(queue *s)
{
    s->front=0;
    s->rear=-1;
}
int full(queue *s)
{
    return ((s->rear+2)%MAX==s->front);//return 1 when full
}
int empty(queue *s)
{
    return ((s->rear+1)%MAX==s->front);//return 1 when empty
}
void addition(queue *s,int num)
{
    if(full(s))
    {
        printf("Queue overflow");
        exit(123);
    }
    s->a[++s->rear]=num;
}
itype substr(queue *s)
{
    if(empty(s))
    {
        printf("Queue underflow");
        exit(321);
    }
    itype data;
    data=s->a[s->front++];
    return data;
}


int main()
{
    queue* p;
    int x;
    p=(queue*)malloc(sizeof(queue));

    initialize(p);

    srand(time(0));
    while (!full(p))
    {
        x=rand()%10;
        printf("ADD %d\n",x);
        addition(p,x);  
    }
    //addition(p,x); //overflow

    while (!empty(p))
    {
        printf("%d\n",substr(p));
    }
    
    //printf("%d\n",substr(p));//underflow
    

    return 0;
}
