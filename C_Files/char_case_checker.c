/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int
main ()
{
  char ch;

  printf ("Enter a char");
  scanf ("%c", &ch);

  if (ch >= 'A' && ch <= 'Z')
    printf ("%c is upper case alphabet", ch);
  else if (ch >= 'a' && ch <= 'z')
    printf ("%c is lower case alphabet", ch);
  else
    printf ("%c is not a alphabet", ch);

  return 0;
}
