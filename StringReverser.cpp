//
// Created by shmuelsuna on 08/01/2020.
//

#include <string>
#include "StringReverser.h"


using namespace std;
string StringReverser::solve(string problom,string soulution) {
// Function to reverse a string

    int n = problom.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++) {
      swap(problom[i], problom[n - i - 1]);
    }
  soulution= problom;
  return soulution;
}
