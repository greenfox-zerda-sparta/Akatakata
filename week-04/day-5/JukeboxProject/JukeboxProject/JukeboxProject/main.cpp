#include <iostream>
#include <string>
#include "Song.h"
#include "RockSong.h"
#include "ReggaeSong.h"
#include "PopSong.h"
#include "Jukebox.h"
// Is there some mess in memory?
// Created song automatically goes to jukebox? Why doing it manually?
// should add function to delete song? 
// get overall song info instead of doing it in parts
using namespace std;

int main() {
  RockSong song1 = RockSong("Halestorm", "Mayhem"); 
  cout << song1.getSong_info();
  song1.rate(5);
  cout << "Adding rates..." << endl;
  song1.rate(5);
  song1.rate(4);
  cout << "Average rating: " << song1.getAvgRating() << endl;
  
  
  ReggaeSong song2 = ReggaeSong("Bob Marley", "Buffalo Soldier");
  cout << song2.getSong_info();
  song2.rate(5);
  song2.rate(3);

  PopSong song3 = PopSong("Queen", "Bohemian Rhapsody");
  cout << song3.getSong_info();
  song3.rate(4);

  RockSong song4 = RockSong("Halestorm", "Mz Hyde");

  Jukebox my_Jukebox;
  my_Jukebox.add_song(song1);
  my_Jukebox.add_song(song2);
  my_Jukebox.add_song(song3);
  my_Jukebox.add_song(song4);

  my_Jukebox.add_rate(song1, 5);
  my_Jukebox.add_rate(song4, 5);
  my_Jukebox.add_rate(song4, 4);
  my_Jukebox.add_rate(song4, 5);
  my_Jukebox.add_rate(song4, 5);
  my_Jukebox.add_rate(song4, 5);
  cout << "Song1 has just got a new rating! Average rating now: " << song1.getAvgRating() << endl;

  cout << "Number of songs in the Jukebox: " << my_Jukebox.getNumber_of_songs() << endl;

  cout << "Halestorm songs overall rating: " << my_Jukebox.get_songrating_by_artist("Halestorm") << endl;
  cout << "Bob Marley songs overall rating: " << my_Jukebox.get_songrating_by_artist("Bob Marley") << endl;
  cout << "Rocks songs rating: " << my_Jukebox.get_rating_by_genre("Rock") << endl;
  cout << my_Jukebox.get_top_rated_title();
  cout << my_Jukebox.get_top_rated_genre();

  return 0;
}