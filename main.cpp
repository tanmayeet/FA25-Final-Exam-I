// Milestone 1
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

void printInRange(const map<string, int>& traffic, int low, int high);

// Milestone 3
void printInRange(const map<string, int>& traffic, int low, int high) {
  cout << "Airports with traffic in range [" << low << ", " << high << "]: \n";

  for (const auto& entry : traffic) {
    if (entry.second >= low && entry.second <= high) {
      cout << entry.first << " " << entry.second << endl;
    }
  }
}

// Milestone 4: Made changes so output matched sample output
int main() {
  map<string, int> traffic;
  ifstream file("210-final-1-FA25-1.txt");
  string origin, dest;

  while (file >> origin >> dest) {
    traffic[origin]++;
    traffic[dest]++;
  }
  cout << "All airport traffic counts:\n";
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

  cout << "\nBusiest airport(s) with count :" << highestTrafficCount << endl;

  for (const auto& entry : traffic) {
    if (entry.second == highestTrafficCount) {
      cout << entry.first << " " << entry.second << endl;
    }
  }
  cout << endl;

  // Testing for Milestone 3
  printInRange(traffic, 5, 8);
  cout << endl;
  printInRange(traffic, 9, 12);

  return 0;
}
