#pragma once
#ifndef JUKEBOX_H
#define JUKEBOX_H
#include <vector>
#include "Song.h"

class Jukebox {
private:
  vector<Song*> allsongs;
  int number_of_songs;
public:
  Jukebox();
  ~Jukebox();
  void add_song(Song& song);
  int getNumber_of_songs();
  void add_rate(Song& song, float _rating);
  float get_songrating_by_artist(string _artist);
  float get_rating_by_genre(string _genre);
  string get_top_rated_title();
  string get_top_rated_genre();
};

#endif // JUKEBOX_H

