// You are going to be given a word. Your job is to return the middle character of the word. If the word's length is odd, return the middle character. If the word's length is even, return the middle 2 characters.

// #Examples:

// Kata.getMiddle("test") should return "es"

// Kata.getMiddle("testing") should return "t"

// Kata.getMiddle("middle") should return "dd"

// Kata.getMiddle("A") should return "A"
// #Input

// A word (string) of length 0 < str < 1000 (In javascript you may get slightly more than 1000 in some test cases due to an error in the test cases). You do not need to test for this. This is only here to tell you that you do not need to worry about your solution timing out.

// #Output

// The middle character(s) of the word represented as a string.

#include <string.h>

/* remember to null-terminate outp! */

char *get_middle(char outp[3], const char *inp)
{
  size_t len = strlen(inp);//длина строки
  if(len % 2 == 0){
    //значит четное, возвращаем 2 средних элемента
    char middle = len / 2;
    outp[0] = inp[middle-1];
    outp[1] = inp[middle];
      outp[2] = '\0';
  }
    if(len % 2 != 0){
        //значит нечетное, возращаем средний элемент
        char middle = len/2;
        outp[0] = inp[middle];
        outp[1] = '\0';
    }
  return outp;
}