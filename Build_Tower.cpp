// Build a pyramid-shaped tower, as an array/list of strings, given a positive integer number of floors. A tower block is represented with "*" character.

// For example, a tower with 3 floors looks like this:

// [
//   "  *  ",
//   " *** ", 
//   "*****"
// ]
// And a tower with 6 floors looks like this:

// [
//   "     *     ", 
//   "    ***    ", 
//   "   *****   ", 
//   "  *******  ", 
//   " ********* ", 
//   "***********"
// ]
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) {
  std::vector<std::string> strVector;
  //первый цикл - находим количество звездочек снизу башни
  int max_stars = 1;
  for(int i = 1; i < nFloors; i++){
    max_stars += 2;
  }
  
  std::string s(max_stars, ' ');
  //отрисовка
  int middle = max_stars / 2; //середина
  int r = middle+1;
  int l = middle-1;
  s[middle] = '*';
  strVector.push_back(s);
  if(nFloors > 1){
  for(int i = 0; i < nFloors-1; i++){
    s[r] = '*';
    s[l] = '*';
    r++;
    l--;
    strVector.push_back(s);
  }
  }
  return strVector;
  //return std::vector<std::string>();
}