
#include<stdio.h>
#include<math.h>

int
main ()
{
  int a, b, c;
  float s, area;
  printf ("enter sides of triangle ");
  scanf ("%d  %d %d", &a, &b, &c);

  s = (a+b+c)/2;

  if(s>a&&s>b&&s>c) 
  {area = sqrt(s*(s-a)*(s-b)*(s-c));
  printf ("%f\n", area);}
  else 
  printf ("the triangle is not closed");
  

}

