/* 
    1. Is there any way to find binary representation of a number like %o for octal %x for hexa 
    2. in loop at line no 36 can which is better pow function or bitwise operator 
    3. In this code, I try to convert a number to its binary form and vice versa
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, bin[32] = {0}; // Need 32 bit binary representation
    
    cout << "Enter a number: " << endl;
    cin >> num;
    
    // Converting number to binary
    for (int i = 0; num != 0; ++i) {
        bin[31 - i] = num % 2;
        num /= 2;
    }
    
    // Printing binary number
    for (int i = 0; i < 32; ++i) {
        cout << bin[i];
        bin[i] = 0; // Initializing value to be zero for future use
    }
    cout << endl;
    
    cout << "Please provide binary input: " << endl;
    
    cin >> num;
    
    // Storing binary num in array
    for (int i = 0; num != 0; ++i) {
        bin[31 - i] = num % 10;
        num /= 10;
    }
    
    int shift = 1;
    
    // Converting binary to decimal using bit shift operator
    for (int i = 0; i < 32; ++i) {
        // num += bin[31 - i] * pow(2, i);
        num += bin[31 - i] * shift;
        shift <<= 1;
        // Using bit shift operator to find power of 2
    }
    
    cout << "After converting, the number is: " << num << endl;
    
    return 0;
}

/* 
    My goal is to solve this problem: https://www.codingninjas.com/studio/problems/reverse-bits_2181102
    
   There is a song concert going to happen in the city. The price of each ticket is equal to
   the number obtained after reversing the bits of a given 32 bits unsigned integer 'n'.

   Sample input For the first test case: Since the given number N = 6 is represented as
   00000000000000000000000000000110 in its binary representation.
   So after reversing the bits, it will become 01100000000000000000000000000000,
   which is equal to 1610612736.

   For the second test case: Since the given number N = 4 is represented as
   00000000000000000000000000000100 in its binary representation.
   So after reversing the bits, it will become 0010000000000000000000000000000,
   which is equal to 536870912 only. 
*/
