// Given an array of ones and zeroes, convert the equivalent binary value to an integer.

// Eg: [0, 0, 0, 1] is treated as 0001 which is the binary representation of 1.

// Examples:

// Testing: [0, 0, 0, 1] ==> 1
// Testing: [0, 0, 1, 0] ==> 2
// Testing: [0, 1, 0, 1] ==> 5
// Testing: [1, 0, 0, 1] ==> 9
// Testing: [0, 0, 1, 0] ==> 2
// Testing: [0, 1, 1, 0] ==> 6
// Testing: [1, 1, 1, 1] ==> 15
// Testing: [1, 0, 1, 1] ==> 11
#include <stddef.h>
#include <math.h>

unsigned binary_array_to_numbers(const unsigned *bits, size_t count){
  size_t dec = 0;
  size_t inc = 0;
  size_t j = count - 1;
  for(size_t i = 0; i < count; i++){
    inc = pow(2, j);
    dec += bits[i] * inc;
    j -= 1;
  }
  return dec;
}