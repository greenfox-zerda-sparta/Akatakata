#include "Jukebox.h"

Jukebox::Jukebox() {
  allsongs = NULL;
  number_of_songs = 0;
}

Jukebox::~Jukebox() {
  if (allsongs != NULL) {
    delete[] allsongs;
    allsongs = NULL;
  }
}

void Jukebox::add_song(Song& song) {
  Song** temp = new Song*[number_of_songs + 1];
  if (allsongs != NULL) {
    for (int i = 0; i < number_of_songs; ++i) {
      temp[i] = allsongs[i];
    }
  }
  temp[number_of_songs] = &song;
  delete[] allsongs;
  allsongs = temp;
  number_of_songs++;
}

int Jukebox::getNumber_of_songs() {
  return number_of_songs;
}


