#pragma once
#ifndef SONG_H
#define SONG_H
#include <vector>
using namespace std;

class Song {
private:
  string artist;
  string title;
  string* genres;
protected:
  string genre;
  vector<float> rating;
public:
  Song(string _artist, string _title);
  ~Song();
  string getSong_info();
  virtual void rate(float _rating) = 0;
  float getAvgRating();
  string getArtist();
  string getTitle();
  string getGenre();
};

#endif
