// Task

// Given an integer n, find the maximal number you can obtain by deleting exactly one digit of the given number.

// Example

// For n = 152, the output should be 52;

// For n = 1001, the output should be 101.

// Input/Output

// [input] integer n

// Constraints: 10 ≤ n ≤ 1000000.

// [output] an integer

#include <vector>
int deleteDigit(int n)
{
  std::vector <int> parts;
  
  //цикл разложения числа на состоявляеющие (c конца)
  int part;
  int count = 0;
  while (n > 0){
    part = n % 10;
    parts.push_back(part);
    n /= 10;
    count++;
  }
  
  //перевернем массив
  std::reverse(parts.begin(), parts.end());
  
  //теперь будем составлять различные комбинации числа
  int tmp;
  tmp += parts[0];
  tmp *= 10;
  
  int max = 0;

  for(int i = 0; i < count; i++){
    tmp = 0;
    for(int j = 0; j < count; j++){
      if(i != j){
        tmp = tmp * 10 + parts[j];
      }
    }
    if(tmp > max){
      max = tmp;
    }
  }
  return max;
}