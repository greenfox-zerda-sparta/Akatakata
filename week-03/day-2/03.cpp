#include <string>
#include <iostream>

using namespace std;

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  CarType type;
  double km;
  double gas;
};

void show(Car* car, string types[]) {
  cout << types[car->type] << " " << car->km << " ";
  if (car->type != TESLA) {
    cout << car->gas;
  }
  cout << endl;
}

// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {
  string CarTypes_names[4] = {"VOLVO", "TOYOTA", "LAND_ROVER", "TESLA"};
  Car Verso;
  Verso.type = CarType::TOYOTA;
  Verso.km = 40000;
  Verso.gas = 7.3;
  show(&Verso, CarTypes_names);
  Car Model_S = {TESLA, 11111, 0};
  show(&Model_S, CarTypes_names);
  return 0;
}
