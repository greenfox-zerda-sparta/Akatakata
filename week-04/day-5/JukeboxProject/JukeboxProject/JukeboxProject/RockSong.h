#pragma once
#ifndef ROCKSONG_H
#define ROCKSONG_H
#include "Song.h"

class RockSong : public Song {
public:
  RockSong(string _artist, string _title);
  ~RockSong();
  bool is_rating_valid(float _rating);
  void rate(float _rating);
};

#endif
