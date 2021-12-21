#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  const int T = 25000;
  int n; cin >> n;
  vector<int> dp(T + 1);
  for (int i = 0, a, b, t; i < n; ++i) {
    cin >> a >> b >> t;
    assert(b != 0 || t != 0);
    if (b) {
      for (int k = 0; k < 32; ++k)
        for (int j = T - t; j >= 0; --j)
          dp[j + t] = max(dp[j + t], dp[j] + a - b * k * k);
    } else {
      for (int j = 0; j <= T - t; ++j)
        dp[j + t] = max(dp[j + t], dp[j] + a);
    }
  }
  int q; cin >> q;
  for (int t; q--;) {
    cin >> t;
    cout << dp[t] << "\n";
  }
}
