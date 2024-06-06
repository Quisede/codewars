// Welcome.

// In this kata you are required to, given a string, replace every letter with its position in the alphabet.

// If anything in the text isn't a letter, ignore it and don't return it.

// "a" = 1, "b" = 2, etc.

// Example

// Input = "The sunset sets at twelve o' clock."
// Output = "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11"

#include <stdlib.h>

// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text) {
    int letter_low = 96;
    int letter_high = 64;
    
    char *out = malloc(strlen(text) * 3 + 1);
    printf("%d\n", letter_low);
    printf("%d\n", letter_high);
    //97 - начало для маленьких, 65 начало для больших
    int index = 0;
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == ' '){
            continue;
        }
        else{
            char current = text[i];
            
            if(current >= 'a' && current <= 'z'){
                //значит в маленьких буквах
                int position = current - letter_low;
                index += sprintf(out + index, "%d ", text[i] - 96);
            }
            else if(current >= 'A' && current <= 'Z'){
                int position = current - letter_high;
                index += sprintf(out + index, "%d ", text[i] - 64);
            }
        }
        if(text[i] >= 0 && text[i] <= 9){
            continue;
        }
    }
    if (index > 0) { // Если есть хотя бы один символ
            out[index - 1] = '\0'; // Заменяем последний пробел на нулевой символ для завершения строки
        } else {
            out[index] = '\0'; // Если в строке не было букв, возвращаем пустую строку
        }
  return out;
}