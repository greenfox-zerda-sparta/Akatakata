#include <iostream>
#include <string>
#include "car.h"
using namespace std;

int main() {
  Car mycar = Car("Toyota", 90000);
  mycar.run(555);
  cout << "Km in my car after running +555 km: " << mycar.getKm() << endl;

  return 0;
}
