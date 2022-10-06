#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  vector<int> d(n, 1e9); d[0] = 0;
  int ans = 1e9;
  for (int i = 1; i < n; ++i) {
    auto prv = d;
    for (int j = n-1; j >= 0; --j) {
      d[j] = 1e9;
      if (j >= i) d[j] = min(d[j], prv[j - i] + v[j]);
      if (j + i < n) d[j] = min(d[j], d[j + i] + v[j]);
    }
    ans = min(ans, d[n-1]);
  }
  cout << ans << "\n";
}
