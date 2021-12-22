#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  auto sum = [&](int mask) {
    LL ans = 0;
    for (int i = 0; i < n; ++i)
      if (mask & (1 << i))
        ans += v[i];
    return ans;
  };
  auto print = [&](int mask) {
    for (int i = 0; i < n; ++i)
      if (mask & (1 << i))
        cout << v[i] << " ";
    cout << "\n";
  };
  unordered_map<int, int> mp;
  for (int mask = 1; mask < (1 << n); ++mask) {
    int s = sum(mask);
    if (mp.find(s) != mp.end()) {
      print(mp[s]);
      print(mask);
      return;
    }
    mp[s] = mask;
  }
  assert(false);
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  for (int c = 1; c <= t; ++c) {
    cout << "Case #" << c << ":\n";
    solve();
  }
}
