// Milestone 1
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

// Milestone 3
void printInRange(const map<string, int> traffic, int low, int high) {
  cout << "Airports within range [" << low << ", " << high << "]: \n";

  for (const auto& entry : traffic) {
    if (entry.second > low && entry.second < high) {
      cout << entry.first << " " << entry.second << endl;
    }
  }
}

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

  // Milestone 2
  int highestTrafficCount = 0;

  for (const auto& entry : traffic) {
    if (entry.second > highestTrafficCount) {
      highestTrafficCount = entry.second;
    }
  }

  cout << "\nBusiest airport(s): " << endl;

  for (const auto& entry : traffic) {
    if (entry.second == highestTrafficCount) {
      cout << entry.first << " " << entry.second << endl;
    }
  }

  return 0;
}