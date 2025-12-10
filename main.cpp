// COMSC210 | Final 1 | Tanmayee Chalamalasetti
// IDE Used: VS Code

// Milestone 1
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, int> traffic;
  ifstream file("210-final-1-FA25-1.txt");
  string origin, dest;

  while (file >> origin >> dest) {
    traffic[origin]++;
    traffic[dest]++;
  }

  for (const auto& entry : traffic) {
    cout << entry.first << " " << entry.second << endl;
  }

  return 0;
}