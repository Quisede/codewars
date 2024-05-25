// Your goal in this kata is to implement a difference function, which subtracts one list from another and returns the result.

// It should remove all values from list a, which are present in list b keeping their order.

// arrayDiff([1,2],[1]) == [2]
// If a value is present in b, all of its occurrences must be removed from the other:

// arrayDiff([1,2,2,2,3],[2]) == [1,3]

#include <stdlib.h>

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {

  int i = 0;
  int j = 0;
  int *arr3 = (int*) malloc(n1 * sizeof(int));
  int k = 0;
  
  for(i = 0; i < n1; i++){
      arr3[i] = arr1[i];
    }
  
  for(i = 0; i < n2; i++){
    for(j = 0, k = 0; j < n1; j++){
      if(arr3[j] == arr2[i]){
        k++;
      }
      else{
        arr3[j - k] = arr3[j];
      }
    }
    n1 -= k;
  }
  *z = n1;
  arr3 = (int*) realloc(arr3, n1 * sizeof(int));
  return arr3;
}