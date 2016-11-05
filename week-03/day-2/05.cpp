#include <string>
#include <iostream>

using namespace std;

// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
//
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a refrence to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
//
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
//
// Create a function that takes an array of houses (and it's length),
// then it creates a new array that consists new houses with the calculated price,
// but all the other properties are the same.

struct House {
  string address;
  int price;
  int rooms;
  int sqrm;
};

bool is_worth_to_buy(House& house, int ref_price) {
  return (house.price / house.sqrm < ref_price);
}

int count_worth_it(House* house, int ref_price, int size) {
  int counter = 0;
  for (int i = 0; i < size; i++) {
    if (is_worth_to_buy(house[i], ref_price)) {
      counter++;
    }
  }
  return counter;
}

House* new_price(House* house, int size, int ref_price) {
  House* newprice_house = new House[size];
  for (int i = 0; i < size; i++) {
    newprice_house[i] = house[i];
    newprice_house[i].price = (newprice_house[i].sqrm * ref_price);
  }
  return newprice_house;
}

int main() {
  int m_price_sqrm = 400;
  House places[] = {
    {"forest", 2341345, 1, 30},
    {"road 66", 2345, 2, 50},
    {"Budapest", 5678, 3, 70},
    {"Neverland", 11111, 11, 90},
    {"Mordor", 26, 1, 1},
    {"Rainbow Springs", 224466, 5, 130}
  };
  int length = 6;
  int number_worth_buy = count_worth_it(places, m_price_sqrm, length);
  House* places_newprice = new House[length];
  places_newprice = new_price(places, length, m_price_sqrm);
  cout << "Is it worth to buy this " << places[0].address << " house: " << is_worth_to_buy(places[0], m_price_sqrm) << endl;
  cout << "Number of houses that are worth to buy: " << number_worth_buy << endl;
  cout << "For example: " << places_newprice[5].address << "," << places_newprice[5].price <<
              ", " << places_newprice[5].rooms << ", " << places_newprice[5].sqrm << endl;

  delete[] places_newprice;
  places_newprice = nullptr;
  return 0;
}
