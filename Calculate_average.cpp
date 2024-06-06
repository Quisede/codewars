// Write a function which calculates the average of the numbers in a given list.

// Note: Empty arrays should return 0.

#include <vector>

double calcAverage(const std::vector<int>& values){
  float sum{};
  int count{};
  for(int x : values){
    sum += x;
    count++;
  }
  if(sum == 0)
    return 0;
  float average = sum / count;
  return average;
}