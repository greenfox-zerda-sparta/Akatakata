#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

// Write a program that creates a text file named alice_words.txt
// containing an alphabetical listing of all the words,
// and the number of times each occurs, in the text version of
// Alice’s Adventures in Wonderland.
// (You can obtain a free plain text version of the book,
// along with many others, from http://www.gutenberg.org.)
//
// The first 10 lines of your output file should look something like this:
//
// Word              Count
// =======================
// a                 631
// a-piece           1
// abide             1
// able              1
// about             94
// above             3
// absence           1
// absurd            2
//
// How many times does the word alice occur in the book?
// What is the longest word in Alice in Wonderland?
// How many characters does it have?

void word_cleaner(string& str) {
  string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while (abc.find(str.at(0)) > abc.length()) {
    str.erase(str.begin());
  }
  while (abc.find(str.at(str.length() - 1)) > abc.length()) {
    str.pop_back();
  }
}

string find_longest(map<string, int>& my_map) {
  string longest = "";
  for (map<string, int>::iterator it = my_map.begin(); it != my_map.end(); it++) {
    if (it->first.length() > longest.length()) {
      longest = it->first;
    }
  }
  return longest;
}

int main() {
  map<string, int> wordlist;
  int count = 0;
  ifstream my_file;
  my_file.open("aliceBook.txt");
  if (my_file.is_open()) {
    string word;
    while (!my_file.eof()) {
      my_file >> word;
      string next_word = word;
      count++;

      try {
        word_cleaner(next_word);
      } catch (...) {
        continue;
      }

      if (wordlist.find(next_word) == wordlist.end()) {
        wordlist[next_word] = 1;
      } else {
        wordlist[next_word]++;
      }
    }
    my_file.close();
    }
    
    ofstream mfile;
    mfile.open("alice-word.txt");
    for (map<string, int>::iterator it = wordlist.begin(); it != wordlist.end(); it++) {
      mfile << it->first << " - " << it->second << endl;
    }
    mfile.close();
      
  
  cout << "Number of words: " << count << endl;
  int total = accumulate(wordlist.begin(), wordlist.end(), 0, [](int value, map<string, int>::value_type& p) { return value + p.second; });

  cout << "Number of values: " << total << endl;
 
  cout << "Number of different words: " << wordlist.size() << endl;

  cout << "How many times does the word alice occur in the book? " << wordlist["Alice"] << endl;
  cout << "What is the longest word in Alice in Wonderland? " << find_longest(wordlist) << endl;
  cout << "How many characters does it have? " << find_longest(wordlist).length() << endl;
  return 0;
}