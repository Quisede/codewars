// Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

// move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}

#include <stddef.h>

void move_zeros(int len, int arr[len])
{
  int i = 0;
  int j = 0; //число ненулевых
  int k = 0;//отметка индекса массива до которой с конца нужно обнулить все элементы 
  
  for(i = 0, j = 0; i < len; i++){
    if(arr[i] != 0){
      arr[j] = arr[i];
      j++;
    }
  }
  
  k = j - 1;
  
  for(i = len - 1; i > k; i--){
    arr[i] = 0;
    }
}