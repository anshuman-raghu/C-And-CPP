
#include <stdio.h>
#include<math.h>
int main()
{   float a,b,c,x,y,d;
    printf("Enter value of a,b,c\n");
    scanf("%f%f%f",&a,&b,&c);
    
    //determinet d=(b*b-4ac)
    d=((b*b)-(4*a*c));
    
    if(d>=0)
    {
        x=(-b+sqrt(d)) / (2*a);
        y=(-b-sqrt(d)) / (2*a);
        printf("two root of eq is %.2f,%.2f",x,y);
    }
    else
    {   
        x= -b/(2*a);
        y= sqrt(-d)/(2*a);
        printf("Real part %f \n imaginary part %f",x,y);
    }   
    return 0;
}
