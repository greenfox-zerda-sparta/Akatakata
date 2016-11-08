#include <string>

using namespace std;

#ifndef PIRATE_H_
#define PIRATE_H_

// create a pirate class
// it should have 2 methods
// drink_rum()
// hows_goin_mate()

class Pirate {
  private:
    string name;
    int rum_number;

  public:
    Pirate(std::string name, int number);
    void drink_rum();
    string hows_goin_mate();
};






#endif /* PIRATE_H_ */
