#include "Jukebox.h"

Jukebox::Jukebox() {
  songs = NULL;
  number_of_songs = 0;
}

Jukebox::~Jukebox() {
  if (songs != NULL) {
    delete[] songs;
    songs = NULL;
  }
}

void Jukebox::push_song(Song& song) {
  Song** temp = new Song*[number_of_songs + 1];
  if (songs != NULL) {
    for (int i = 0; i < number_of_songs; ++i) {
      temp[i] = songs[i];
    }
  }
  temp[number_of_songs] = &song;
  delete[] songs;
  songs = temp;
  number_of_songs++;
}