
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int itype;
typedef struct node
{
    itype info;
    struct node *link;
}node;

typedef struct list
{
    node* head,*tail;
}list;

void initialize(list *lp)
{
    lp->head=NULL;lp->tail=NULL;
}

node* CreateNode(itype x)
{
        node *p;

    p = (node*)malloc(sizeof(node));
    if (p==NULL)
    {
        printf("Memory not allocated:");
        exit(1);
    }
    p->info = x;
    p->link = NULL;
    return p;
}
void insert(list *lp,itype x)
{
    node *p;
    p=CreateNode(x);
    if(lp->head==NULL)
        lp
}
