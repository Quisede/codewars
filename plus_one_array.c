// Given an array of integers of any length, return an array that has 1 added to the value represented by the array.

// the array can't be empty
// only non-negative, single digit integers are allowed
// Return nil (or your language's equivalent) for invalid inputs.

// Examples

// Valid arrays

// [4, 3, 2, 5] would return [4, 3, 2, 6]
// [1, 2, 3, 9] would return [1, 2, 4, 0]
// [9, 9, 9, 9] would return [1, 0, 0, 0, 0]
// [0, 1, 3, 7] would return [0, 1, 3, 8]

// Invalid arrays

// [1, -9] is invalid because -9 is not a non-negative integer

// [1, 2, 33] is invalid because 33 is not a single-digit integer
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *up_array(const int *arr, unsigned int *count)
{
  //проверяем входящий массив на соответствие условиям 
  int error_arr = 0;
  if(*count == 0){
    return NULL;
  }
  for(unsigned int i = 0; i < *count; i++){
    if(arr[i] < 0 || arr[i] > 9){
      error_arr = 1;
      break;
    }
  }
  
  if(error_arr == 1){
    *count = 0;
    return NULL;
  }
  

  //добавим флаг, на проверку, если массив состоит только из девяток
  int arr_nine = 1;
  for(unsigned int i = 0; i < *count; i++){
    if(arr[i] != 9){
      arr_nine = 0;
      break;
    }
  }
  
  int *arr_out;
  
  if(arr_nine == 1){
    *count += 1;
    arr_out = (int *)malloc(*count * sizeof(int));
    arr_out[0] = 1;
    for(unsigned int i = 1; i < *count; i++){
      arr_out[i] = 0;
    }
  }
  else{
    arr_out = (int *)malloc(*count * sizeof(int));
    for(unsigned int i = 0; i < *count; i++){
      arr_out[i] = arr[i];
    }
    
    for(int j = *count - 1; j >= 0; j--){
      if(arr_out[j] >= 0 && arr_out[j] < 9){
        arr_out[j] += 1;
        break;
      }
      else if(arr_out[j] == 9){
        arr_out[j] = 0;
      }
    }
  }
  return arr_out;
  }
  


 
  /*создадим выходной динамический массив, копию входного массива, с которой будем работать далее
  int *arr_out = (int*) malloc(*count + 1 * sizeof(int));
  for(unsigned int i = 0; i < *count; i++){
    arr_out[i] = arr[i];
  }
  
  //алгоритм обработки массива
  for(unsigned int j = *count - 1; j >= 0; j--){
    if(arr_out[j] >= 0 && arr_out[j] < 9){
      arr_out[j] += 1;
      break;
    }
    if(arr_out[j] == 9){
      arr_out[j] = 0;
      if(arr_out[j - 1] < 9){
        arr_out[j - 1] += 1;
        break;
      }
      }
  }
  
  
  *count = strlen(arr_out);*/