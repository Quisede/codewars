// Digital root is the recursive sum of all the digits in a number.

// Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.

// Examples

//     16  -->  1 + 6 = 7
//    942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
// 132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
// 493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
#include <stdio.h>
#include <stdlib.h>


int digital_root(int n) {
  //посчитаем длину вводимого числа
  int count = 0;
  int summ = 0;
  int originalN = n;
  
  while(n > 0){
    n = n / 10;
    count += 1;
  }
  //цикл, разделяющий входящее число по цифрам и записывает их в специальный массив по отдельности
  int *arr = (int*) malloc(count * sizeof(int));
  count = 0; //обнуляем счетчик, для подсчета кол-ва цифр в следующем числе
  n = originalN;
  
  for(int i = 0; n > 0; i++){
    arr[i] = n % 10;
    count += 1;
    n = n / 10;
  }
  
  for(int i = 0; i < count; i++){
    summ += arr[i];
  }
  
  free(arr);
  
  while(count > 1){
    arr = (int*) malloc(count * sizeof(int));
    count = 0;
    n = summ;
    
    for(int i = 0; n > 0; i++){
      arr[i] = n % 10;
      count += 1;
      n = n / 10;
    }
    
    summ = 0;
    for(int i = 0; i < count; i++){
      summ = summ + arr[i];
    }
    
    free(arr);
  }
  
  return summ;
}