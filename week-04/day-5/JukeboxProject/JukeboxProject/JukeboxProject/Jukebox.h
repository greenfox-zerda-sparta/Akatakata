#pragma once
#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "Song.h"

class Jukebox {
private:
  Song** allsongs;
  int number_of_songs;
public:
  Jukebox();
  ~Jukebox();
  void add_song(Song& song);
  int getNumber_of_songs();
  void add_rate(Song& song, float _rating);
};

#endif // JUKEBOX_H

