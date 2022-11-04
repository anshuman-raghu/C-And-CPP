#include<stdio.h>
#define pi 3.14

int main()
{
    int r;
    float area;
    
    printf("enter radius of circle\n");
    scanf("%d", &r);
    area= pi*r*r;
    
    printf("the area of circle is %f", area);
    
    return 0;

}
