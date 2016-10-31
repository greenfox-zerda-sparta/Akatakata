#include <iostream>
#include <string>

using namespace std;

void diceroll(int &array) {
  int stats[12] = {};
  int all_cases = 0;
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      stats[i + j] += 1;
      all_cases++;
    }
  }
  cout << "Possibilities and probabilities when rolling with two dice:" << endl;
  for (int i = 2; i <= 12; i++) {
    float prob = float(stats[i]) / all_cases * 100;
    cout << i << " occurs in " << stats[i] << " case(s). Probability: " << prob << "%." <<  endl;
  }
}

int main() {
  // Write a program that calculates all the possible combinations with rolling two dices.
  // It should print each value how many times occures.
  // for example 3 occures 2 times because 1 + 2 and 2 + 1
  int dice[6][6] = {
      {1, 2, 3, 4, 5, 6},
      {1, 2, 3, 4, 5, 6}
  };

  diceroll(dice[6][6]);

  return 0;
}
