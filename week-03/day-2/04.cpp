#include <string>
#include <iostream>

using namespace std;

struct Pirate {
  string name;
  bool has_wooden_leg;
  short int gold_count;
};

// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg
// struct Pirates ki van toltve.
// create array of Pirates ,
// functions for sum gold, avg gold, richest

int sum_golds(Pirate* arr, int size) {
  short int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i].gold_count;
  }
  return sum;
}

float avg_gold(Pirate arr[], int size) {
  return float(sum_golds(arr, size)) / size;
}

string find_richest_with_woodenleg(Pirate arr[], int size) {
  Pirate richest = {"", false, 0};
  for (int i = 0; i < size; i++ ) {
    if (arr[i].has_wooden_leg == true && arr[i].gold_count > richest.gold_count) {
        richest = arr[i];
    }
  }
  return richest.name;
}

int main() {
  Pirate pirates[] = {
    {"Jack", false, 18},
    {"Uwe", true, 8},
    {"Hook", true, 12},
    {"Halloween kid", false, 0},
    {"Sea Wolf", true, 14},
    {"Morgan", false, 1}
  };
  int golds = sum_golds(pirates, 6);
  int average_gold = avg_gold(pirates, 6);
  string richest_wl = find_richest_with_woodenleg(pirates, 6);
  cout << "Golds of pirates: " << golds << endl;
  cout << "The average gold of a pirate is: " << average_gold << endl;
  cout << "The richest pirate with wooden leg is: " << richest_wl << endl;
  return 0;
}
