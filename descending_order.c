// Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

// Examples:

// Input: 42145 Output: 54421

// Input: 145263 Output: 654321

// Input: 123456789 Output: 987654321

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
uint64_t descendingOrder(uint64_t n)
{
  uint64_t n2 = n; //копируем исходное число в вспомогательную переменную
  int i = 0;
  uint64_t tmp = 0;
  int flag = OUT;
  uint64_t* arr; //указатель на массив 
  int k = 0; //кол-во эл-в массива
   //найдем кол-во элементов в массиве k, с помощью деления числа
  while(n != 0){
    n = n / 10;
    k++;
  }
  //выделение памяти под массив
   arr = (uint64_t*)malloc(k * sizeof(uint64_t));
  //записываем цифры в массив из исходного числа
  for(i = 0; i < k; i++){
    arr[i] = n2 % 10;
    n2 /= 10;
  }
  //сортировка массива
  for(i = k - 1; i >= 0; i--){
    flag = IN;
    for(int j = 0; j < i; j++){
      if(arr[j] < arr[j + 1]){
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        flag = OUT;
      }
    }
    if(flag == IN)
      break;
  }
  
  uint64_t result = 0;
    for (i = 0; i < k; i++) {
        result = result * 10 + arr[i];
    }
  
  free(arr);
  
  return result;
}