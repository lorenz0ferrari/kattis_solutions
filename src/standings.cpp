#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s >> v[i];
    --v[i];
  }
  sort(v.begin(), v.end());
  LL bad = 0;
  for (int i = 0; i < n; ++i) {
    bad += abs(i - v[i]);
  }
  cout << bad << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
