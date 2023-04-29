#include<iostream>
#include<process.h>

#include<stdlib.h>
#include<time.h>
#define SIZE 20

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
node* insertInTree(node* root,itemType data)
{
    node* p,*newNode;
    newNode=createNode(data);

    if(root==NULL)
    {
        root=newNode;
    }
    else
    {
        p=root;
        bool finish=false;

        while(!finish)
        {
            if(newNode->x<p->x)
            {
                if(p->left==NULL)
                    {
                        p->left=newNode;
                        finish=true;
                    }
                else    
                    p=p->left;
            }
            else {		/*(newNode->item >= p->item)	 new node is larger, go to left subtree*/
					if (p->right == NULL) {			/*right subtree is empty, position found */
					p->right = newNode;
					finish=true;
				}
				else										/*left subtree is not empt, search in left*/
					p = p->right;
			}
        }
    }
    return root;
}
node* createTree(itemType L[],int n)
{
    node* root;
    root=NULL;
    for(int i=0;i<n;++i)
    {
        root=insertInTree(root,L[i]);
    }
    return root;
}
void fill(itemType L[],int n)
{
    srand(time(0));
    for(int i=0;i<n;++i)
        L[i]=rand()%97;
}
void show(itemType L[],int n)
{
    srand(time(0));
    for(int i=0;i<n;++i)
        cout<<L[i]<<" ";
}
void treeSort(itemType L[],int n)
{
    node *root;
    root=createTree(L,n);
    


}
int main()
{
    itemType L[SIZE];
    int n;
    cin>>n;
    fill(L,n);
    show(L,n);

    treeSort(L,n);
    show(L,n);

}