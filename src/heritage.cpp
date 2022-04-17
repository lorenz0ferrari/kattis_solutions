#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 1e9 + 7;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  string name; cin >> name;
  vector<pair<string, LL>> v(n);
  for (auto& [a, b] : v) {
    cin >> a >> b;
  }
  int m = name.size();
  vector<LL> dp(m+1); dp[0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (const auto& [a, b] : v) {
      int k = a.size();
      if (i >= k && name.substr(i-k, k) == a) {
        dp[i] = (dp[i] + (dp[i-k]) * b) % mod;
      }
    }
  }
  cout << dp[m] << "\n";
}
