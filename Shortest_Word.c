// Simple, given a string of words, return the length of the shortest word(s).

// String will never be empty and you do not need to account for different data types.
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

ssize_t find_short(const char *s)
{
  //прогоняем указатель по строке, ищем пробелы считая длину каждого слова и заносим в спец переменную, в конце выводим
  size_t len = strlen(s); //длина всей строки
  int flag = 0;// 0 - вне слова, 1 - в слове
  ssize_t short_count = len; //мин длина слова
  int current_count = 0;
    
  for(int i = 0; i < len; i++){
    if(s[i] != ' '){
      //значит находимся в слове, flag ставим на 0
      flag = 0;
    }
    else{
      flag = 1;
      if(current_count <= short_count){
        short_count = current_count;
        current_count = 0;
      }
      else{
        current_count = 0;
      }
    }
    
    if(flag != 1){
      //если находимся в слове, то считаем кол-во букв в этом слове
      current_count += 1;
    }
  }
    
    if(current_count <= short_count){
      short_count = current_count;
      current_count = 0;
    }
    
  return short_count;
}