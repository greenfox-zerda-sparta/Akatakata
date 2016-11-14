#pragma once
#ifndef SONG_H
#define SONG_H
#include <vector>
using namespace std;

class Song {
private:
  string artist;
  string title;
protected:
  string genre;
  vector<float> rating; // vector of ratings
public:
  Song(string _artist, string _title);
  ~Song();
  string getSong_info();
  string getGenre();
  //float getRating();
  virtual void rate(float _rating) = 0;
  float getAvgRating();

};

#endif // !Song.h
