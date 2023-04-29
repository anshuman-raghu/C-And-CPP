#include<iostream>
#include<process.h>

#include<stdlib.h>
#include<time.h>

using namespace std;

typedef int itemType;

typedef struct node{
    itemType x;
    node* left,*right;
    
}node;

node* createNode(itemType data)
{
    node* p;
    p= new node;
    if(p==NULL)
    {
        cout<<"Memory not allocated";
        exit(1);
    }

    p->x=data;
    p->left=NULL;
    p->right=NULL;

    return p;
}
node* insertInTree(node *root,itemType x)
{
    node* p,*NewNode;
    NewNode=createNode(x);

    if(root==NULL)
    {
        root=NewNode;
    }
    else
    {
        bool finish=true;
        p=root;
        while(finish)
        {
            if(NewNode->x<p->x)
            {
                if(p->left==NULL)
                {
                    p->left=NewNode;
                    finish=false;
                }
                else{
                    p=p->left;
                }
                
            }
            else{
                if(p->right==NULL)
                {
                    p->right=NewNode;
                    finish=false;
                }
                else{
                    p=p->right;
                }
            }
        }
    }
    return root;
}
node* createTree()
{
    node* root;
    root=NULL;
    itemType x;
    int n;
    cout<<"Enter How many node you want in tree : ";
    cin>>n;
    srand(time(0));


    for(int i=0;i<n;++i)
    {
        x=rand()%101;
        root=insertInTree(root,x);
    }
    return root;

}
void displayTree(node *root,int level)
{

    if(root==NULL)
    {
        for(int i=0;i<level;++i)
        {
            cout<<"     ";
        }
        cout<<"~"<<endl;
        return ;
    }
    else{
        node* p;
        p=root;
        displayTree(p->right,level+1);
        for(int i=0;i<level;++i)
        {
            cout<<"     ";
        }
        cout<<p->x<<endl;
        displayTree(p->left,level+1);
    }
}
node* search(node* root,itemType x)
{
    node* p;
    p=root;
    while(p!=NULL)
    {
        if(p->x==x)
        return p;
        else if(x<p->x)
            p=p->left;
        else
            p=p->right;
    }

}
itemType deleteNode(node **p)
{
    node* q;
    itemType data;

    if(*p==NULL)
        cout<<"Cannot delete Empty node"<<endl;
    else if((*p)->right==NULL)
    {
        q=*p;
        (*p)=(*p)->left;
    }
    else if((*p)->left==NULL)
    {
        q=*p;
        *p=(*p)->right;
    }
    else{//both subtree exist;
        for(q=(*p)->right;q->left!=NULL;q=q->left)
            ;
        q->left=(*p)->left;
        q=*p;
        *p=(*p)->right;
    }
    data=q->x;
    delete(q);
    return data;

}
int main()
{
    node* root;
    root=createTree();

    displayTree(root,0);
    itemType x;
    cout<<"Enter Item to be serch in tree: ";
    cin>>x;
    node*p;
    p=search(root,x);
    if(p==NULL)
    {
        cout<<"\n item not found "<<endl;
    }
    else{
        cout<<"Searched item is :"<<p->x;
        cout<<"Which node you want to delete \n press 1 for left child, any other number for right child: ";
        int choice;
        cin>>choice;
        if(choice==1)
            x=deleteNode(&(p->left));
        else
        {
            x=deleteNode(&p->right);
        }
        displayTree(root,0);
        cout<<"The deleted node item was: "<<x;
    }
    return 0;
}

