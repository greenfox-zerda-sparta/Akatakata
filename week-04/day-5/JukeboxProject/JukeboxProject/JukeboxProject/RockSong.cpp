#include <iostream>
#include "Song.h"
#include "RockSong.h"

using namespace std;
 
RockSong::RockSong(string _artist, string _title) : Song(_artist, _title) {
  genre = "Rock";
}

bool RockSong::is_rating_valid(float _rating) {
  if (_rating < 0 || _rating > 5) {
    return false;
  }
  else if (_rating == 1) {
    cout << "Rock songs cannot get such a bad rating :) \n";
    return false;
  }
  return true;
}

void RockSong::rate(float _rating) {
  if (is_rating_valid(_rating) == true) {
    rating.push_back(_rating);
  }
}

RockSong::~RockSong() {}
