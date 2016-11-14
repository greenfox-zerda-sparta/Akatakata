#pragma once
#ifndef REGGAESONG_H
#define REGGAESONG_h
#include "Song.h"

class ReggaeSong : public Song {
public:
  ReggaeSong(string _artist, string _title);
  ~ReggaeSong();
  bool is_rating_valid(float _rating);
  void rate(float _rating);
};

#endif
