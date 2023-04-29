#include <iostream>
#include<stdlib.h>
#include<time.h>
#define MAX 5
#define SIZE 20
using namespace std;

typedef int dataType;

typedef struct node
{
    dataType x;
    node* left,*right;
}node;

typedef node* itemType;

typedef struct stack
{
    int top;
    itemType a[MAX];
}stack;



void initialize(stack *p)
{
    p->top=-1;
}
int full(stack *p)
{
    return p->top==MAX-1;
}
int empty(stack *p)
{
    return p->top==-1;
}
void push(stack* p,itemType x)
{
    if(full(p))
    {
        cout<<"stack overflowed"<<endl;
        exit(2);
    }
    ++p->top;
    p->a[p->top]=x;
}
itemType pop(stack *p)
{
    if(empty(p))
    {
        cout<<"stack UnderFLow"<<endl;
        exit(3);
    }
    itemType x;
    x=p->a[p->top];
    p->top--;
    return x;
}
node* createNode(dataType data)
{
    node* p;
    p=new node;
    if(p==NULL)
    {
        cout<<"mem";
    }
    p->x=data;
    p->left=NULL;
    p->right=NULL;
    return p;

}
node* insertInTree(itemType root,dataType x)
{
    itemType p,newNode;
    newNode=createNode(x);
    bool finish=true;
    if(root==NULL)
    {
        root=newNode;
    }
    else
    {
        p=root;
        while(finish)
        {
            if(newNode->x <= p->x)
            {
                if(p->left==NULL)
                {
                    p->left=newNode;
                    finish=0;
                }
                else
                    p=p->left;
            }
            else{
                if(p->right==NULL)
                {
                    p->right=newNode;
                    finish=0;
                }
                else{
                    p=p->right;
                }
            }
        }
    }
    return root;
}
// node* createTree()
// {
//     node* root=NULL;
//     dataType data;
//     int n;

//     cout<<"Enter count of node in tree"<<endl;
//     cin>>n;

//     srand(time(0));

//     for(int i=0;i<n;++i)
//     {
//         data=rand()%97;
//         root= insertInTree(root,data);
//     }

//     return root;

// }
void displayTree(node* root,int level)
{
    if(root==NULL)
    {
        for(int i=0;i<level;++i)
        {
            cout<<"     ";
        }
        cout<<"~"<<endl;
    }
    else{
        displayTree(root->right,level+1);
        for(int i=0;i<level;++i)
        {
            cout<<"     ";
        }
        cout<<root->x<<endl;

        displayTree(root->left,level+1);

    }
}
// void inorder(node* root)
// {
//     stack s;
//     initialize(&s);
//     node* p;
    
//     p=root;
//     while(1)
//     {
//         while(p!=NULL)
//         {
//             push(&s,p);
//             p=p->left;
//         }
//         if(!empty(&s))
//         {
//             p=pop(&s);
//             cout<<p->x<<"  ";
//             p=p->right;
//         }
//         else
//             break;
//     }
// }
node* createTree(dataType L[],int n)
{
    node* root;
    root=NULL;
    for(int i=0;i<n;++i)
    {
        root=insertInTree(root,L[i]);
    }
    return root;
}
void fill(dataType L[],int n)
{
    srand(time(0));
    for(int i=0;i<n;++i)
        L[i]=rand()%97;
}
void show(dataType L[],int n)
{
    srand(time(0));
    for(int i=0;i<n;++i)
        cout<<L[i]<<" ";
    cout<<endl;
}
void treeSort(dataType L[],int n)
{
    node *root,*p;
    root=createTree(L,n);
    stack s;
    initialize(&s);
    p=root;

    int i=0;
    while(1)
    {
        while(p!=NULL)
        {
            push(&s,p);
            p=p->left;
        }  
        if(!empty(&s))
        {
            p=pop(&s);
            L[i++]=p->x;
            p=p->right;
        }
        else   break;
    }



}
int main()
{
    dataType L[SIZE];
    int n;
    cin>>n;
    fill(L,n);
    show(L,n);

    treeSort(L,n);
    show(L,n);

}



