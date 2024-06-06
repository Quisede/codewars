// Write two functions that convert a roman numeral to and from an integer value. Multiple roman numeral values will be tested for each function.

// Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals:

// 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC
// 2008 is written as 2000=MM, 8=VIII; or MMVIII
// 1666 uses each Roman symbol in descending order: MDCLXVI.
// Input range : 1 <= n < 4000

// In this kata 4 should be represented as IV, NOT as IIII (the "watchmaker's four").

// Examples

// to roman:
// 2000 -> "MM"
// 1666 -> "MDCLXVI"
//   86 -> "LXXXVI"
//    1 -> "I"

// from roman:
// "MM"      -> 2000
// "MDCLXVI" -> 1666
// "LXXXVI"  ->   86
// "I"       ->    1
// Help

// +--------+-------+
// | Symbol | Value |
// +--------+-------+
// |    M   |  1000 |
// |   CM   |   900 |
// |    D   |   500 |
// |   CD   |   400 |
// |    C   |   100 |
// |   XC   |    90 |
// |    L   |    50 |
// |   XL   |    40 |
// |    X   |    10 |
// |   IX   |     9 |
// |    V   |     5 |
// |   IV   |     4 |
// |    I   |     1 |
// +--------+-------+

#include <string>
#include <vector>

class RomanHelper{
  std::vector<std::pair<int, std::string>> roman_numerals = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
  public:
    std::string to_roman(unsigned int n){
    std::string str;
      
    for(const auto& pair : roman_numerals){
      while(n >= pair.first){
        str+=pair.second;
        n-=pair.first;
      }
    }
      return str;
    }
  
    int from_roman(std::string rn){
      int n = 0;
      int i = 0;
      while(i < rn.size()){
        for(const auto& pair : roman_numerals){
          const std::string& current = pair.second;
          if(rn.substr(i, current.size()) == current){
            n += pair.first;
            i+=current.size();
            break;
          }
        }
      }
      return n;
    }
} RomanNumerals;