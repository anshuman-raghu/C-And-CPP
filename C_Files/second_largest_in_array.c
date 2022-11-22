#include <stdio.h>

int second_largest(int num1, int num2, int num3, int num4) {
  int largest;
  if (num1 >= num2 && num1 >= num3 && num1 >= num4) {
    largest = num1;
  } else if (num2 >= num1 && num2 >= num3 && num2 >= num4) {
    largest = num2;
  } else if (num3 >= num1 && num3 >= num2 && num3 >= num4) {
    largest = num3;
  } else {
    largest = num4;
  }

  int second_largest;
  if (num1 != largest && num1 >= num2 && num1 >= num3 && num1 >= num4) {
    second_largest = num1;
  } else if (num2 != largest && num2 >= num1 && num2 >= num3 && num2 >= num4) {
    second_largest = num2;
  } else if (num3 != largest && num3 >= num1 && num3 >= num2 && num3 >= num4) {
    second_largest = num3;
  } else if (num4 != largest) {
    second_largest = num4;
  }

  return second_largest;
}

int main(void) {
  printf("%d\n", second_largest(1, 2, 3, 4));
  printf("%d\n", second_largest(4, 3, 2, 1));
  printf("%d\n", second_largest(5, 5, 5, 4));
  printf("%d\n", second_largest(1, 1, 1, 1));
  return 0;
}
