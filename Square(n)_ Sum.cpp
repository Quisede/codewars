// Complete the square sum function so that it squares each number passed into it and then sums the results together.

#include <vector>

int square_sum(const std::vector<int>& numbers)
{
    int summ{};
    for(int x : numbers){
      int tmp = x*x;
      summ += tmp;
    }
    return summ;
}