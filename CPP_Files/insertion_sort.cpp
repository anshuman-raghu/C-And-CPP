#include<stdlib.h>
#include<iostream>
int shiftcout=0;
using namespace std;

#define MAX 20
typedef int item;

void fill(item list[],int n);
void show(item list[],int n);
void sort(item list[],int n);

int main()
{
    item list[MAX];
    int n;
    
    cout<<"Enter the size of list: ";
    cin>>n;
    
    fill(list,n);
    show(list,n);
    sort(list,n);
    show(list,n);
    
    cout<<shiftcout;

    return 0;
}

void fill(item list[],int n)
{
    srand(time(0));
    for(int i=0;i<n;++i)
    {
        list[i]=rand()%101;
    }
}

void show(item list[],int n)
{
    cout<<"List is: ";
    for(int i=0;i<n;++i)
    {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}
void sort(item list[],int n)
{
item temp;
int j,h;
for(h=n/3; h>=1; h=h/3)
{
    for(int i=0;i<n;++i)
    {
        j=i;
        while(list[j]<list[j-h])
        {
            temp=list[j];
            list[j]=list[j-h];
            list[j-h]=temp;
            j--;
        }
    }
}
    
}



