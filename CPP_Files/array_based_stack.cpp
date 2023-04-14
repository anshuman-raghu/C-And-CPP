
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAX 3

typedef char itype;
typedef struct stack{
    itype a[MAX];
    int top;
}stack;

void initialize(stack *p);
int full(stack *p);
int empty(stack *p);
void push(stack *p,itype x);
itype pop(stack *p);
itype peak(stack *p);



int main()
{
    stack s;
    itype x;
    
    initialize(&s);
    push(&s,'a');
    push(&s,'b');
    cout<<peak(&s)<<endl;
    cout<<pop(&s)<<endl;
    cout<<pop(&s)<<endl;
    return 0;
}
void initialize(stack *p)
{p->top=-1;}

int full(stack *p){return p->top==MAX-1;}
int empty(stack *p){return p->top==-1;}
void push(stack *p,itype x)
{
    if(full(p))
    {
        printf("stack overflow\n");
        exit(100);
    }
    p->a[++(p->top)]=x;
}
itype pop(stack *p)
{
    if(empty(p))
    {
        printf("stack underflow");
        exit(200);
    }
    return p->a[p->top--];
}
itype peak(stack *p)
{
    if(empty(p))
    {
        printf("stack is empty");
    }
    return p->a[p->top];
}


