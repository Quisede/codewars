// Complete the function so that it finds the average of the three scores passed to it and returns the letter value associated with that grade.

// Numerical Score	Letter Grade
// 90 <= score <= 100	'A'
// 80 <= score < 90	'B'
// 70 <= score < 80	'C'
// 60 <= score < 70	'D'
// 0 <= score < 60	'F'
char getGrade(int a, int b, int c) {
  int grade = (a + b + c) / 3;
  if(grade >= 0 &&  grade < 60) {return 'F';}
  if(grade >= 60 &&  grade < 70) {return 'D';}
  if(grade >= 70 && grade < 80) {return 'C';}
  if(grade >= 80 &&  grade < 90) {return 'B';}
  if(grade >= 90 &&  grade <= 100) {return 'A';}
}