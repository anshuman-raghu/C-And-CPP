#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef int itype;

void fill(itype *arr,int n)
{
    srand(time(0));
    for(int i=0;i<n;++i)
    {
        arr[i]=(rand()%13);
    }
}
void show(itype *arr,int n)
{
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void selectionSort(itype list[], int n)
{
    int i, loc, min;
    itype temp;

    for (loc=0; loc<n-1; ++loc)
    {
        min = loc;
        for (i=loc+1; i<n; ++i)
        {
            if (list[i]<list[min])
                min = i;
        }
        if (loc != min)
        {
            temp = list[min];
            list[min] = list[loc];
            list[loc] = temp;
        }
    }
}

void bubbleSort(itype list[], int n)
{
    int i, current, pass;
    itype temp;

    current = n-1;
    for (pass=0; pass<n-1; ++pass)
    {
        for (i=0; i<current; ++i)
        {
            if (list[i]>list[i+1])
            {
                temp = list[i];
                list[i] = list[i+1];
                list[i+1]= temp;
                
            }
        }
        --current;
    }
}

void insertionSort(itype L[], int n)
{
    int i, current;
    itype temp;

    for (current=1; current<n; ++current)
    {
        temp = L[current];
        for (i=current-1; i>=0; --i)
        {
            if (L[i]>temp)
            {
                L[i+1] = L[i];
            }
            else
                break;
        }
        L[i+1] = temp;

    }

}


int main()
{
    int n;
    cout<<"Enter Size of list"<<endl;
    cin>>n;

    itype list[n];

    fill(list,n);
    show(list,n);

    //selectionSort(list,n);
    //bubbleSort(list,n);
    insertionSort(list,n);
    show(list,n);
} 