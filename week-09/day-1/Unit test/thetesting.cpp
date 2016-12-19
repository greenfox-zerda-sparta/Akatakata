#define TEST // comment out this line in order to run main()
#ifdef TEST
#include "test_thetesting.cpp"
#endif

#ifndef TEST
#include <iostream>
#include "WordToolBox.h"
using namespace std;

int main() {
  WordToolBox wSource("Tarzan's toenails");
  cout << "countHowMany(\"a\")=" << wSource.countHowMany('a') << endl; // countHowMany("a")=3
  cout << "countHowMany(\"T\")=" << wSource.countHowMany('T') << endl; // countHowMany("//T")=2
  cout << "countHowMany(\"t\")=" << wSource.countHowMany('t') << endl; // countHowMany("t")=2
  cout << "countHowMany(\"x\")=" << wSource.countHowMany('x') << endl; // countHowMany("x")=0
  cout << "countHowMany(\" \")=" << wSource.countHowMany(' ') << endl; // countHowMany(" ")=1
  
  WordToolBox w("folate");
  w.setStringHeld("folate");
  string alternatives[6] = { "falsetto", "latest", "foetal","aloft","float","flota" };
  for (int i = 0; i < 6; ++i) {
    cout << "is " << alternatives[i] << " an anagram of " << w.getStringHeld() << " = " << w.isAnnagram(alternatives[i]) << endl;
  }
  cout << endl << "New test" << endl;
  w.setStringHeld("aloft");
  for (int i = 0; i < 6; ++i) {
    cout << "is " << alternatives[i] << " an anagram of " << w.getStringHeld() << " = " << w.isAnnagram(alternatives[i]) << endl;
  }

  return 0;
}

#endif