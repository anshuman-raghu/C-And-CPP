#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

typedef int itype;

typedef struct node{
    itype info;
    node *link;
}node;

typedef struct list{
    node *head,*tail;
}list;


node *createNode(itype x)
{
    node* p;
    p=new node;
    if(p==NULL)
    {
        cout<<"memory not allocated:";
        exit(125);
    }
    
    p->info=x;
    p->link=NULL;
    return p;
}
void insertAtTail(list *lp, itype x)
{
    node *p;
    p=createNode(x);
    if(lp->head==NULL)
        lp->head=p;
    else
        lp->tail->link=p;
    lp->tail=p;
}
void initialize(list *lp)
{
    lp->head=NULL;lp->tail=NULL;
}
list *createList(int n)
{
    list *lp;
    lp=new list;
    if(lp==NULL)
    {
        cout<<"Memory not allocated";
        exit(564);
    }
    
    initialize(lp);
    
    srand(time(0));
    
    for(int i=0;i<n;++i)
    {
        insertAtTail(lp,rand()%99);
    }
    return lp;
}
void show(list *lp){
    node *p;
    p=lp->head;
     cout<<"List is:";
    
    while(p!=NULL)
    {
        cout<<p->info<<"->";
        p=p->link;
    }
    
    cout<<"NULL:)"<<endl;
    
}

void insertAtHead(list *lp, itype x);
void insertAfter(node * given, itype x);
void insertBefore(list *lp, node * given, itype x);

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

    printf("Enter item to be inserted at head: ");
    scanf("%d", &x);
    insertAtHead(lp, x);
    show(lp);

    printf("Enter item to be inserted at tail: ");
    scanf("%d", &x);
    insertAtTail(lp, x);
    show(lp);

    given = lp->head->link->link;
    //given is now pointing to third node
    printf("Enter item to be inserted after given node: ");
    scanf("%d", &x);
    insertAfter(given, x);
    show(lp);

    printf("Enter item to be inserted before given node: ");
    scanf("%d", &x);
    insertBefore(lp, given, x);
    show(lp);

    //deleteList(lp);
    return 0;
}

void insertBefore(list *lp, node * given, itype x)
{
    node *p, *newp;
    if (given==NULL)
    {
        printf("Invalid pointer");
        exit(1);
    }

    //traverse the list till p is poisitioned one node before given
    for (p=lp->head; p->link!=given; p=p->link);

    newp = createNode(x);
    newp->link = given;
    p->link = newp;
}

void insertAfter(node *given, itype x)
{
    node * p;
    if (given==NULL)
    {
        printf("Invalid pointer");
        exit(1);
    }
    p = createNode(x);
    p->link = given->link;
    given->link = p;
}

void insertAtHead(list *lp, itype x)
{
    node *p;
    p = createNode(x);
    if (lp->head==NULL)  //empty list
        lp->tail = p;
    else
        p->link = lp->head;
    lp->head = p;
}

