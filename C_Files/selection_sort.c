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
        printf("Memory not aliated\n");
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


void selectionSort(iType *list, int n);

int compCount=0;
int swapCount=0;

int main()
{
    int n;
    iType *list;
    printf("Enter the current size: ");
    scanf("%d", &n);

    list = generateFill(n);
    show(list, n);
    selectionSort(list, n);
    show(list, n);

    printf("Count of Comparisions: %d\nCount of swaps: %d\n", compCount, swapCount);

    free(list);
    return 0;
}

void selectionSort(iType *list, int n)
{
    int min;
    iType temp;

    for (int i=0; i<n-1; ++i)
    {
        min = i;
        for (int j=i+1; j<n; ++j)
        {
            ++compCount;
            if (list[j]<list[min])
                min = j;
        }
        if (i != min)
        {
            ++swapCount;
            temp = list[min];
            list[min] = list[i];
            list[i] = temp;
        }
    }
}
