// // Find the sum of the digits of all the numbers from 1 to N (both ends included).

// Examples

// # N = 4
// 1 + 2 + 3 + 4 = 10

// # N = 10
// 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + (1 + 0) = 46

// # N = 12
// 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + (1 + 0) + (1 + 1) + (1 + 2) = 51
int compute_sum(int n) {
  //создадим копию исходного числа n
  int n_copy = n;
  int summ = 0;
  int count = 0;
  
  for(int i = 0; i <= n; i++){
    int current_summ = i;
    while(current_summ > 0){
      summ = summ + current_summ % 10;
      current_summ = current_summ / 10;
    }
  }
  
  return summ;
  }