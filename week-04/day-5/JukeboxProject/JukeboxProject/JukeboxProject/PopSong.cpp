#include "PopSong.h"

PopSong::PopSong(string _artist, string _title) : Song(_artist, _title) {
  genre = "Pop";
}

bool PopSong::is_rating_valid(float _rating) {
  if (_rating < 0 || _rating > 5) {
    return false;
  }
  return true;
}

void PopSong::rate(float _rating) {
  if (is_rating_valid(_rating) == true) {
    rating.push_back(_rating);
  }
}

PopSong::~PopSong() {}
