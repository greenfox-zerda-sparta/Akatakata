#include <vector>
#include <iostream>
#include "Song.h"
#include "Jukebox.h"

Jukebox::Jukebox() {
  allsongs = {};
  number_of_songs = 0;
}

Jukebox::~Jukebox() {}

void Jukebox::add_song(Song& song) {
  allsongs.push_back(&song);
  number_of_songs++;
}

int Jukebox::getNumber_of_songs() {
  return number_of_songs;
}

void Jukebox::add_rate(Song& song, float _rating) {
  song.rate(_rating);
}

float Jukebox::get_songrating_by_artist(string _artist) { // IF THERE IS NO RATING OR NO SONG BY ARTIST!! 
  vector<float> songs_by = {}; // should use new?
  for (int i = 0; i < number_of_songs; ++i) {
    if (allsongs[i]->getArtist() == _artist) {
      songs_by.push_back(allsongs[i]->getAvgRating());
    }
  }
  float sum = 0;
  for (int i = 0; i < songs_by.size(); i++) {
    sum += songs_by[i];
  }
  return sum / songs_by.size();
}
