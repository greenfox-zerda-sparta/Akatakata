#pragma once
#ifndef POPSONG_H
#define POPSONG_H
#include "Song.h"
class PopSong : public Song {
public:
  PopSong(string _artist, string _title);
  bool is_rating_valid(float _rating);
  void rate(float _rating);
  ~PopSong();
};
#endif


