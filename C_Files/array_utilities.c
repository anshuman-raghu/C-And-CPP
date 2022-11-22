#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int iType;

iType *generateFill(int n)
{
    iType *list;
    list = (iType*)malloc(n*sizeof(iType));
    if (list==NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    srand(time(0));
    for (int i=0; i<n; ++i)
        list[i]=rand()%100;

    return list;
}
void show(iType *list, int n)
{
    printf("List is: ");
    for (int i=0; i<n; ++i)
        printf("%d\t", list[i]);
    printf("\n");
}