#include "Song.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Song::Song(string _artist, string _title) {
  artist = _artist;
  title = _title;
}

Song::~Song() {
}

string Song::getSong_info() {
  return artist + ": " + title + ". " + getGenre() + "\n";
}

string Song::getGenre() {
  return genre;
}

float Song::getAvgRating() {
  float rates_sum = 0;
  for (unsigned int i = 0; i < rating.size(); i++) {
    rates_sum += rating[i];
  }
  float avg_rating = rates_sum / rating.size();
  return avg_rating;
}

string Song::getArtist() {
  return artist;
}

string Song::getTitle() {
  return title;
}