#include <stdio.h>

int main()
{   int d,n,b=0,x;

    printf("enter a digit");
    scanf("%d",&d);
    d=n;
    while(d)
    {
        x=d%2;
        b=b*10+x;
        
        d=d/2;
    }
    printf("the binary of %d is %d",n,b);
    return 0;
}
