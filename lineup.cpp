#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  bool dec = true;
  bool inc = true;

  vector <string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (i && v[i] < v[i - 1]) inc = false;
    if (i && v[i] > v[i - 1]) dec = false;
  }

  if (dec) {
    cout << "DECREASING" << "\n";
  } else if (inc) {
    cout << "INCREASING" << "\n";
  } else {
    cout << "NEITHER" << "\n";
  }
}
