// The objective is to return all pairs of integers from a given array of integers that have a difference of 2.

// The result array should be sorted in ascending order of values.

// Assume there are no duplicate integers in the array. The order of the integers in the input array should not matter.

// Examples

// [1, 2, 3, 4]  should return [[1, 3], [2, 4]]

// [4, 1, 2, 3]  should also return [[1, 3], [2, 4]]

// [1, 23, 3, 4, 7] should return [[1, 3]]

// [4, 3, 1, 5, 6] should return [[1, 3], [3, 5], [4, 6]]

#include <utility>
#include <vector>

std::vector<std::pair<int, int>> twos_difference(const std::vector<int> &vec) {
  std::vector<std::pair<int, int>> result;
  
  std::vector<int> sorted_vec = vec; // Создаем копию входного вектора

  // Сортируем вектор для упрощения поиска пар
   std::sort(sorted_vec.begin(), sorted_vec.end());
  
  for(int i = 0; i < vec.size(); i++){
    for(int j = 0; j < vec.size(); j++){
      if(sorted_vec[j] - sorted_vec[i] == 2){
        result.push_back(std::make_pair(sorted_vec[i], sorted_vec[j]));
      }
    }
  }
  
  return result;
}