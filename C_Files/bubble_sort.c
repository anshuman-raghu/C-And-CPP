#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int iType;

iType *generateFill(int n)
{
    iType *list;
    list = (iType *)malloc(n*sizeof(iType));
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
void bubbleSort(iType *list, int n);

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
    bubbleSort(list, n);
    show(list, n);

    printf("Count of Comparisions: %d\nCount of swaps: %d\n", compCount, swapCount);

    free(list);
    return 0;
}

void bubbleSort(iType *list, int n)
{
    int current;
    iType temp;

    current = n-1;
    //outer loop for n-1 ies
    for (int i=0; i<n-1; ++i)
    {
        //inner loop to compare adjacent items
        for (int j=0; j<current; ++j)
        {
            //++compCount;
            if (list[j]>list[j+1])
            {
                //++swapCount;
                temp = list[j];
                list[j] = list[j+1];
                list[j+1]= temp;
                
            }
        }
        //system("pause");
        //show(list, n);
        --current;
    }
}