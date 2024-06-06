// Write a function that accepts an integer n and a string s as parameters, and returns a string of s repeated exactly n times.

// Examples (input -> output)

// 6, "I"     -> "IIIIII"
// 5, "Hello" -> "HelloHelloHelloHelloHello"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repeat_str(size_t count, const char *src)
{
  int len = strlen(src); //длина входной строки
  int len2 = count * len;
  int k = 0;
  char* array = (char*) malloc((len2 + 1) * sizeof(char)); //создаем строку на выход в виде динамического массива
  if(count == 0){
    array[0] = '\0';
    return array;
  }
  
  for(size_t i = 0; i < count; i++)
    for(int j = 0; j < len; j++){
      array[k++] = src[j];
    }
  array[len2] = '\0';
  return array;
}

  //return calloc(1, 1);