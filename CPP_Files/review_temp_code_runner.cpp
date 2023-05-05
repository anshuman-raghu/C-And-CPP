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
int main()
{
    node* root;
    root=createTree();

    displayTree(root,0);
    return 0;

}

