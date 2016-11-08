#include <string>
#ifndef CAR_H_
#define CAR_H_

// Create a class called "Car"
// It should have a "type" property that stores the car's type in a string eg: "Mazda"
// It should have a "km" property that stores how many kilometers it have run
class Car {
  private:
    std::string type;
    unsigned int km;
  public:
    Car(std::string type, unsigned int km);

    void run(int number);

    unsigned int getKm();
};





#endif /* CAR_H_ */
