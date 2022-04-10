#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int k; cin >> k;
  int yy; cin >> yy;
  int pp; cin >> pp;
  vector<array<int, 2>> v(n+k-2);
  for (auto& [a, b] : v) {
    cin >> a >> b;
  }
  sort(v.begin(), v.end());
  set<int> best;
  int ans = -1;
  for (int y = 2011, i = 0; y < 2011+k; ++y) {
    if (yy == y) best.insert(pp);
    while (i < n+k-2 && v[i][0] == y) best.insert(v[i++][1]);
    if (*prev(best.end()) == pp) ans = y;
    best.erase(prev(best.end()));
  }
  cout << (ans == -1 ? "unknown" : to_string(ans)) << "\n";
}
