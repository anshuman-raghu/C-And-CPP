
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fill(int a[],int num);
void show(int a[],int num);
void intial(int a[]);

int main()
{
    int a[7],num;
    //a[0]=face 1,   a[1]=face 2,   a[2]=face  3...
    printf("Enter number of throw:");
    scanf("%d",&num);
    
    intial(a);  // for giving every element value 0
    
    fill (a,num);
    show (a,num);
    return 0;
}
void intial(int a[])
{
    for (int i=0;i<7;++i)
    {
        a[i]=0;
    }
}

int fill(int a[],int num)
{
    int face;
    
    srand(time(0));
    for (int i=0;i<num;++i)
        a[rand()%6+1]++;

    return 0;
}
void show(int a[],int num)
{
    for (int i=1;i<7;++i)
    printf("face %d : count %d : probability %.3f\n",i,a[i],a[i]/(float)num);
}


