#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
#include<fstream>
using namespace std;

vector<int> Vec;
map<int, int> Map;

int main() {
  int n;
  while (cin >> n) {
    if (Map[n] == 0) {
      Vec.push_back(n);
      Map[n]++;
    }
    else
      Map[n]++;
  }
  for (int i = 0; i < Vec.size(); i++) {
    cout << Vec[i] << " " << Map[Vec[i]] << "\n";
  }
  return 0;
}
