#include <iostream>
#include "ReggaeSong.h"

ReggaeSong::ReggaeSong(string _artist, string _title): Song(_artist, _title) {
  genre = "Reggae";
}

bool ReggaeSong::is_rating_valid(float _rating) {
  if (_rating < 0 || _rating > 5) {
    return false;
  }
  else if (_rating == 5) {
    std::cout << "Reggae songs cannot get such a good rating :) \n";
    return false;
  }
  return true;
}

void ReggaeSong::rate(float _rating) {
  if (is_rating_valid(_rating) == true) {
    rating.push_back(_rating);
  }
}

ReggaeSong::~ReggaeSong() {}
