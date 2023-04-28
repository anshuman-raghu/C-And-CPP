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
    node *head, *tail;
}list;


node *createNode(itype x)
{
    node *p;

    p = new(node);
    p->info = x;
    p->link = NULL;
    return p;
}
void insertAtTail(list *lp, itype x)
{
    node *p;
    p = createNode(x);
    if (lp->head==NULL)
        lp->head = p;
    else
        lp->tail->link = p;
    lp->tail = p;
}

void initialize(list *lp)
{lp->head = NULL; lp->tail=NULL;}

list *createList(int n)
{
    list *lp;

    lp = new list[2];
    initialize(lp);

    srand(time(0));
    for(int i=0; i<n; ++i)
        insertAtTail(lp, rand()%100);
    return lp;
}

void show(list *lp)
{
    node *p;

    p = lp->head;
    printf("List is: ");
    while(p!=NULL)
    {
        printf("%d-->", p->info);
        p=p->link;
    }
    printf("NULL\n\n");
}

void reverse(list *lp);

int main()
{
    list *lp;
    itype x;
    int n;
    node *given;

    printf("enter size of list: ");
    scanf("%d", &n);
    lp = createList(n);
    show(lp);
    reverse(lp);
    show(lp);
    return 0;
}

void reverse(list *lp)
{
    node *p, *q, *r;

    p =lp->head; q = p->link; r = q->link;
    while(q!=NULL)
    {
        q->link = p;
        p = q;
        q = r;
        if (r!=NULL) r = r->link;
    }
    p = lp->head;
    lp->head = lp->tail;
    lp->tail = p;
    lp->tail->link = NULL;
}