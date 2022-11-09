
#include <stdio.h>

int main()
{   int n,d,s=0;
    printf("Enter 3 digit number\n");
    scanf("%d",&n);
    
    if(n>99 && n<1000)
    { 
        d = n%10;
        s += d;
        n = n/10;
        
        d = n%10;
        s += d;
        n = n/10;
        
        d = n%10;
        s += d;
        n = n/10;
        
        
        
       printf("the sum of 3 digit is %d",s);
    
    }   
    else
    printf("the number is not a 3 digit ");
    return 0;
}
