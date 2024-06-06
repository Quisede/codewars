// Given the string representations of two integers, return the string representation of the sum of those integers.

// For example:

// sumStrings('1','2') // => '3'
// A string representation of an integer will contain no characters besides the ten numerals "0" to "9".

// I have removed the use of BigInteger and BigDecimal in java

// Python: your solution need to work with huge numbers (about a milion digits), converting to int will not work.
#include <string>
#include <vector>
std::string sum_strings(const std::string& a, const std::string& b) {
  //найдем длину первого числа
  int len_1 = a.size();
  int len_2 = b.size();
  int maxlen;
  
  if(len_1 > len_2){
    maxlen = len_1;
  }
  else{
    maxlen = len_2;
  }
  
  std::vector<int> result(maxlen + 1, 0);
  std::string output;
  
  int i = len_1 - 1;
  int j = len_2 - 1;
  int flag = 0; //флаг переноса
  int summ = 0;
  int num_1;
  int num_2;
  
  while(i >= 0 || j >= 0 || flag != 0){
    if(i >= 0){
      num_1 = a[i] - '0';
    }
    else{
      num_1 = 0;
    }
    
    if(j >= 0){
      num_2 = b[j] - '0';
    }
    else{
      num_2 = 0;
    }
    
    summ = num_1 + num_2 + flag;
    result[maxlen--] = summ % 10;
    flag = summ / 10;
    i--;
    j--;
  }
  
  //получили число в массиве vector, теперь надо поэлементно занести это все в строку
  int flag_start = 1;
  for(int k = 0; k < result.size(); k++){
    if(result[k] == 0 && flag_start == 1){
      continue;
    }
    flag_start = 0;
    output += result[k] + '0';
  }
  
  if(output.empty() == 1){
    return "0";
  }
  return output;
}