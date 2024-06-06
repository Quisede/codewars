// In this kata you are given a string for example:

// "example(unwanted thing)example"
// Your task is to remove everything inside the parentheses as well as the parentheses themselves.

// The example above would return:

// "exampleexample"
// Notes

// Other than parentheses only letters and spaces can occur in the string. Don't worry about other brackets like "[]" and "{}" as these will never appear.
// There can be multiple parentheses.
// The parentheses can be nested.

#include <string>

std::string remove_parentheses(const std::string &str)
{
  std::string output_str;
  int flag = 0;
  int count = 0;
  
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '('){
      flag = 1;
      count++;
    }
    else if(str[i] == ')'){
      flag = 0;
      count--;
    }
    
    if(flag == 0 && str[i] != ')' && count == 0){
      output_str += str[i];
    }
  }
    return output_str; 
}
