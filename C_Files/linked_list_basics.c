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

    lp = (list*)malloc(sizeof(list));
    if (lp==NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
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


int main()
{
    list *lp;
    int n;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    lp = createList(n);
    show(lp);
    return 0;
}