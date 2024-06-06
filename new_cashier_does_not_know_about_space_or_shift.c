// Some new cashiers started to work at your restaurant.

// They are good at taking orders, but they don't know how to capitalize words, or use a space bar!

// All the orders they create look something like this:

// "milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza"

// The kitchen staff are threatening to quit, because of how difficult it is to read the orders.

// Their preference is to get the orders as a nice clean string with spaces and capitals like so:

// "Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke"

// The kitchen staff expect the items to be in the same order as they appear in the menu.

// The menu items are fairly simple, there is no overlap in the names of the items:

// 1. Burger
// 2. Fries
// 3. Chicken
// 4. Pizza
// 5. Sandwich
// 6. Onionrings
// 7. Milkshake
// 8. Coke
// dynamically allocate memory for the return
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *get_order(const char *input) {
  int menu_size = 8;
  int item_count[menu_size];
  const char *menu[] = {"burger", "fries", "chicken", "pizza", "sandwich", "onionrings", "milkshake", "coke"};
  char *formatted_order = malloc(256 * sizeof(char));
  //заполним созданный массив нулями
  for(int i = 0; i < menu_size; i++){
    item_count[i] = 0;
  }
  
  for(int i = 0; i < menu_size; i++){
    const char *found = strstr(input, menu[i]);
    while(found){
      item_count[i]++;
      found = strstr(found + strlen(menu[i]), menu[i]);
    }
  }
  
  strcpy(formatted_order, "");
  for(int i = 0; i < menu_size; i++){
    for(int j = 0; j < item_count[i]; j++){
      strcat(formatted_order, menu[i]);
      strcat(formatted_order, " ");
    }
  }
  
  formatted_order[strlen(formatted_order) - 1] = '\0';
  
  //обрабатываем выходной массив, заменяя первые буквы каждого слова на заглавные (самую первую букву заменяем отдельно)
  formatted_order[0] = formatted_order[0] - 'a' + 'A';
  for(int i = 0; i < strlen(formatted_order); i++){
    if(formatted_order[i-1] == ' '){
      formatted_order[i] = formatted_order[i] - 'a' + 'A';
    }
  }
  
  return formatted_order;
}



  /*char menu_sh[] = {'b', 'u', 'f', 'r', 'c', 'h', 'p', 'i', 's', 'a', 'o', 'n', 'm', 'i', 'c', 'o'};
  char menu_ln[][12] = {"Burger", "Fries", "Chicken", "Pizza", "Sandwich", "Onionrings", "Milkshake", "Coke"};
  int len_menu_sh = 16;
  int len_input = strlen(input);
  int k = 0;
  char **arr_out = malloc(1000 * sizeof(char*));

  for (int j = 0; j < len_input; j += 2) {
    for (int i = 0; i < len_menu_sh; i += 2) {
      if ((input[j] == menu_sh[i]) && (input[j + 1] == menu_sh[i + 1])) {
        arr_out[k] = malloc((strlen(menu_ln[i / 2]) + 1) * sizeof(char));
        strcpy(arr_out[k], menu_ln[i / 2]);
        k++;
      }
    }
  }

  return arr_out;*/



 /* //создадим массив с меню в нужном порядке
  char const *menu[] = {"burger", "fries", "chicken", "pizza", "sandwich", "onionrings", "milkshake", "coke"};
  char int len  = {6, 5, 7, 5, 8, 10, 9, 4};
  int index = 0;
  int len_menu = 8;
  int len_input = strlen (input);
  int *arr_out = (int*) malloc(len_input*2 * sizeof(int));
  
  for(int i = 0; i < len_menu; i++){
    for(int j = 0; j < len_input; j ++){
      if(input[i] )
    }
  } */