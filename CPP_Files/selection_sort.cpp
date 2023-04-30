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
    int min;
    item temp;
    

    for(int i=0;i<n-1;++i)
    {
        min=i;
        for(int j=i+1;j<n;++j)
        {
            if(list[j]<list[min])
                min=j;
        }
        if(i!=min)
        {
            temp=list[min];
            list[min]=list[i];
            list[i]=temp;
            
            show(list,n);
        }

    }
}
