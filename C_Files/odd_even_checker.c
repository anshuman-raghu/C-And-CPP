
#include <stdio.h>

int
main ()
{
  int a;
  printf ("enter a number\n");
  scanf ("%d", &a);

  if (a < 100 && a > 0)
    {
      if (a % 2 == 0)
	printf ("%d is even and less than 100", a);
      else
	printf ("%d is odd and less than 100", a);
    }

  else if (a % 2 == 0)
    {
      printf ("%d is even and greater than 100", a);
      else
      printf ("%d number is odd and greater than 100", a);
    }
  return 0;
}
