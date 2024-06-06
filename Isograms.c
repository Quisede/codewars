// An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

// Example: (Input --> Output)

// "Dermatoglyphics" --> true
// "aba" --> false
// "moOse" --> false (ignore letter case)
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool IsIsogram (const char *string) 
{
  int len = strlen(string);
  
  if(len == 0)
    return true;
  else if(len == 1)
    return true;
  else if(len > 1){
    for(int i = 0; i < len - 1; i++){
      for(int j = i + 1; j < len; j++){
        char el1 = string[i];
        char el2 = string[j];
        
        if(el1 >= 'a' && el1 <= 'z')
          el1 = el1 - 'a' + 'A';
        if(el2 >= 'a' && el2 <= 'z')
          el2 = el2 - 'a' + 'A';
        if(el1 == el2)
          return false;
      }
    }
    return true;
  }

}