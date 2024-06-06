// Finish the solution so that it takes an input n (integer) and returns a string that is the decimal representation of the number grouped by commas after every 3 digits.

// Assume: 0 <= n < 2147483647

// Examples

//        1  ->           "1"
//       10  ->          "10"
//      100  ->         "100"
//     1000  ->       "1,000"
//    10000  ->      "10,000"
//   100000  ->     "100,000"
//  1000000  ->   "1,000,000"
// 35235235  ->  "35,235,235"

#include <string>

std::string group_by_commas(int n)
{
  if(n == 0){
    return "0";
  }
  int tmp = n;
  /*
  int lenght = 0;
  while (tmp > 0){
    tmp /= 10;
    lenght++;
  }
  
  //нашли длину числа, далее важна кратность трём
  int count_comma = 0;
  tmp = n;
  while(tmp > 0){
    tmp /= 3;
    count_comma += 1;
  }
  */
  //нашли количество запятых, теперь заполняем строку в соотвествии с этим (заполнять будем с конца)
  //int lenght_str = lenght + count_comma;
  tmp = n;
  int count_paste = 0;
  std :: string str;
  while(tmp > 0){
     str += (tmp % 10) + '0';
      tmp /= 10;
      count_paste++;
    
      if((count_paste % 3) == 0 && tmp > 0){
        str += ',';
        count_paste = 0;
      }
  }
  
  std::reverse(str.begin(), str.end());
  return str;
}