#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  LL h; cin >> h;
  string s; cin >> s;
  LL root = 1;
  for (char c : s) {
    if (c == 'L') root *= 2;
    else root = root * 2 + 1;
  }
  cout << (1LL << (h+1) - root << "\n";
}
