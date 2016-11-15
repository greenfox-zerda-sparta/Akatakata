#include <iostream>
#include <string>
#include "Song.h"
#include "RockSong.h"
#include "ReggaeSong.h"
#include "PopSong.h"
#include "Jukebox.h"
// Songs should be constructed as new and allsongs vector in Jukebox is new too.
// Edge cases.
// Get overall song info instead of doing it in parts.

using namespace std;

int main() {
  cout << "Adding a song..." << endl;
  RockSong song1 = RockSong("Halestorm", "Mayhem"); 
  cout << song1.getSong_info();
  song1.rate(5);
  cout << "Adding rates...(5, 5, 4)" << endl;
  song1.rate(5);
  song1.rate(4);
  cout << "Average rating: " << song1.getAvgRating() << endl << endl;
  
  cout << "Adding a song..." << endl;
  ReggaeSong song2 = ReggaeSong("Bob Marley", "Buffalo Soldier");
  cout << song2.getSong_info();
  cout << "Adding rates...(5, 3)" << endl;
  song2.rate(5);
  song2.rate(3);

  cout << endl << "Adding a pop song and one more rock song..." << endl;
  PopSong song3 = PopSong("PopArtist", "PopSong");
  song3.rate(4);
  RockSong song4 = RockSong("Halestorm", "Mz Hyde");

  Jukebox my_Jukebox;
  my_Jukebox.add_song(song1);
  my_Jukebox.add_song(song2);
  my_Jukebox.add_song(song3);
  my_Jukebox.add_song(song4);

  cout << endl << "Adding some ratings via Jukebox..." << endl;
  my_Jukebox.add_rate(song1, 5);
  my_Jukebox.add_rate(song4, 5);
  my_Jukebox.add_rate(song4, 4);
  my_Jukebox.add_rate(song4, 5);
  my_Jukebox.add_rate(song4, 5);
  my_Jukebox.add_rate(song4, 5);

  cout << song1.getSong_info() << " - has just got a new rating! Average rating now: " << song1.getAvgRating() << endl << endl;

  cout << "Number of songs in the Jukebox: " << my_Jukebox.getNumber_of_songs() << endl << endl;

  cout << "Halestorm songs overall rating: " << my_Jukebox.get_songrating_by_artist("Halestorm") << endl;
  cout << "Bob Marley songs overall rating: " << my_Jukebox.get_songrating_by_artist("Bob Marley") << endl << endl;
  cout << "Rock songs rating: " << my_Jukebox.get_rating_by_genre("Rock") << endl << endl;
  cout << my_Jukebox.get_top_rated_title();
  cout << my_Jukebox.get_top_rated_genre();

  return 0;
}