
#include <stdio.h>
#include<math.h>
#define pi 3.14

int main()
{   float r, h, a, v;
    printf("enter radius and hight of cone\n");
    scanf("%f %f", &r, &h);
    
    a=pi*r*(r+(sqrt(h*h+r*r)));
     printf("area of cone = %f\n", a);
     
    v=pi*r*r*(h/3);
    
    printf("volume of cone is %f", v);

    return 0;
}
  
