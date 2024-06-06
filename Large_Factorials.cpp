// In mathematics, the factorial of integer n is written as n!. It is equal to the product of n and every integer preceding it. For example: 5! = 1 x 2 x 3 x 4 x 5 = 120

// Your mission is simple: write a function that takes an integer n and returns the value of n!.

// You are guaranteed an integer argument. For any values outside the non-negative range, return null, nil or None (return an empty string "" in C and C++). For non-negative numbers a full length number is expected for example, return 25! =  "15511210043330985984000000"  as a string.

// For more on factorials, see http://en.wikipedia.org/wiki/Factorial

// NOTES:

// The use of BigInteger or BigNumber functions has been disabled, this requires a complex solution

// I have removed the use of require in the javascript language.

#include <string>
#include <vector>

std::string factorial(int factorial){
  std::vector res(1,1);
  
  for(int k = 2; k <= factorial; k++){
    int flag = 0;
    
    for(int i = 0; i < res.size(); i++){
      int mult = res[i] * k + flag;
      res[i] = mult % 10;
      flag = mult / 10;
    }
    
    while (flag){
      res.push_back(flag % 10);
      flag /= 10;
    }
  }
  
  std::string str;
  for(int i = 0; i < res.size(); i++){
    str += res[i] + '0';
  }
  
  std::reverse(str.begin(), str.end());
  return str;
}