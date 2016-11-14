#include <iostream>
#include <string>
#include "Song.h"
#include "RockSong.h"
#include "ReggaeSong.h"
#include "PopSong.h"

using namespace std;

int main() {
  RockSong song1 = RockSong("Halestorm", "Mayhem"); 
  cout << song1.getSong_info();
  // ADDING RATES DOES NOT WORK!
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
  song3.rate(5);
  return 0;
}