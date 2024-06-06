// Create a function that takes a positive integer and returns the next bigger number that can be formed by rearranging its digits. For example:

//   12 ==> 21
//  513 ==> 531
// 2017 ==> 2071
// If the digits can't be rearranged to form a bigger number, return -1 (or nil in Swift, None in Rust):

//   9 ==> -1
// 111 ==> -1
// 531 ==> -1

#include <string>

long nextBigger(long n) {
  std::string str;
  
  long tmp = n;
  int count = 0;
  while(tmp > 0){
    str += (tmp % 10) + '0';
    tmp /= 10;
    count++;
  }
  
  std::reverse (str.begin(), str.end());
  int i;
  int j;
  for(int i = count - 1; i > 0; i--){
    if(str[i] > str[i-1]){
      j = count - 1;
      while(str[j] <= str[i-1]){
        j--;
      }
      std::swap(str[i-1], str[j]);
      std::reverse(str.begin() + i, str.end());
      break;
      }
  }
  
  
  long n_2 = 0;
  for(int i = 0; i < count; i++){
    n_2 = n_2 * 10 + (str[i] - '0'); // Преобразуем символ обратно в цифру и добавляем к числу
  }
  
  // Проверяем, если n_2 все еще меньше или равно n, возвращаем -1
  if(n_2 <= n) {
    return -1;
  }
  
  return n_2;
  /*
  long find = 5000;
  
  long tmp = n;
  
  int count = 0;
  while(tmp > 0){
    tmp /= 10;
    count++;
  }
  
  int i = 0;
  std::vector<int>arr(count);
  tmp = n;
  while (tmp > 0){
    arr[i] = tmp % 10;
    tmp /= 10;
    i++;
  }
  
  long current = 0;
  
  for(int i = 0; i < count; i++){
    
    if(current > n && current < find){
      find = current;
    }
    current = 0;
    
    current += arr[i];
    current *= 10;
    for(int j = 0; j < count; j++){
      if(j == i){
        continue;
      }
      else{
      current += arr[j];
      current *= 10;
        }
    }
    
  }
  
  if(find > n){
    return find;
  }
  else{
    return -1;
  }*/
}