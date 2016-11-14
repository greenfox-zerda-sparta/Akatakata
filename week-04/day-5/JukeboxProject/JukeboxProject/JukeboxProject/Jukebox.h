#pragma once
#ifndef JUKEBOX_H
#define JUKEBOX_H
#include "Song.h"

class Jukebox {
private:
  Song** songs;
  int number_of_songs;
public:
  Jukebox();
  ~Jukebox();
  void push_song(Song& song);
};

#endif // JUKEBOX_H

