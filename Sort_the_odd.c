// Task

// You will be given an array of numbers. You have to sort the odd numbers in ascending order while leaving the even numbers at their original positions.

// Examples

// [7, 1]  =>  [1, 7]
// [5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
// [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]
#include <stdlib.h>
#include <malloc.h>

void sort_array(size_t n, int arr[n]) {
    //создадим два вспомогательных подмассива для занесения четных и нечетрых значений
    int* arr_1 = malloc(n * sizeof(int));//нечетные
  int k = 0;
  
  for(int i = 0; i < n; i++){
    if(arr[i] % 2 != 0){
      arr_1[k++] = arr[i];
    }
  }
    
    //теперь отсортируем подмассивы
    for(int i = 0; i < k-1; i++){
        for(int j = i + 1; j < k; j++){
            if(arr_1[i] > arr_1[j]){
                int tmp = arr_1[i];
                arr_1[i] = arr_1[j];
                arr_1[j] = tmp;
            }
        }
    }
    
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 != 0){
            arr[i] = arr_1[j];
            j++;
        }
    }

    free(arr_1);
}