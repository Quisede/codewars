// Complete the function that accepts a string parameter, and reverses each word in the string. All spaces in the string should be retained.

// Examples

// "This is an example!" ==> "sihT si na !elpmaxe"
// "double  spaces"      ==> "elbuod  secaps"

#include <stdlib.h>

char* reverseWords(const char* text) {
  //передается указатель на строку, надо перевернуть
  //находим слова, запоминаем конечные и начальные коорданты слова и переворачиваем двигаясь к центур
  int flag = 0;//0 - вне слова
  int start = 0;
  int end = 0;
    char tmp;
  
    char* text_1 = malloc(strlen(text) + 1);
    strcpy(text_1, text);

  for(int i = 0; i <= strlen(text_1); i++){
    if(text_1[i] != ' ' && text_1[i] != '\0'){
      //значит находимся в слове
      if(flag == 0){
        //значит на первой позиции, запоминаем
        start = i;
      }
      flag = 1; //устанавливаем флаг
    }
    
    else if(text_1[i] == ' ' || text_1[i] == '\0'){
      flag = 0;
        if(text[i-1] != ' '){
            end = i - 1;
            //теперь переворачиваем
            while(start < end){
                tmp = text_1[start];
                text_1[start] = text_1[end];
                text_1[end] = tmp;
                start++;
                end--;
            }
        }
    }
   
  }
    return text_1;
}