#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;

string s;
string mn;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  mn = s;

  int n = s.size();
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string a = s.substr(0, i);
      string b = s.substr(i, j - i);
      string c = s.substr(j, n - j);

      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      reverse(c.begin(), c.end());

      string nw = a + b + c;

      mn = min(mn, nw);
    }
  }

  cout << mn << "\n";
}
