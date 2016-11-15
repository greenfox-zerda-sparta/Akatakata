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
  song.getAvgRating();
}

float Jukebox::get_songrating_by_artist(string _artist) { // IF THERE IS NO RATING OR NO SONG BY ARTIST!! 
  vector<float> songs_by = {}; // should use new?
  for (int i = 0; i < number_of_songs; ++i) {
    if (allsongs[i]->getArtist() == _artist) {
      songs_by.push_back(allsongs[i]->getAvgRating());
    }
  }
  float sum = 0;
  for (unsigned int i = 0; i < songs_by.size(); i++) {
    sum += songs_by[i];
  }
  return sum / songs_by.size();
}

float Jukebox::get_rating_by_genre(string _genre) {
  vector<float> genre_songs = {}; // should use new?
  for (int i = 0; i < number_of_songs; ++i) {
    if (allsongs[i]->getGenre() == _genre) {
      genre_songs.push_back(allsongs[i]->getAvgRating());
    }
  }
  float sum = 0;
  for (unsigned int i = 0; i < genre_songs.size(); i++) {
    sum += genre_songs[i];
  }
  return sum / genre_songs.size();
}

string Jukebox::get_top_rated_title() { // IF EQUAL RATES ?
  Song* base = allsongs[0];
  for (int i = 0; i < number_of_songs; ++i) {
    if (allsongs[i]->getAvgRating() > base->getAvgRating()) {
      base = allsongs[i];
    }
  }
  return "Top rated song is: " + base->getSong_info() + '\n';
}

string Jukebox::get_top_rated_genre() { // IF EQUAL RATES ?
  string genres[3] = { "Rock", "Pop", "Reggae" };
  int num_of_genres = 3;
  float genre_rating[3] = { get_rating_by_genre("Rock"), get_rating_by_genre("Pop"), get_rating_by_genre("Reggae") };
  float highest = genre_rating[0];
  int highest_idx = 0;
  for (int i = 0; i < num_of_genres; i++) {
    if (genre_rating[i] > highest) {
      highest = genre_rating[i];
      highest_idx = i;
    }
  }
  return "Top rated genre is: " + genres[highest_idx] + '\n';
}