/*

dp[sum] = minimum number of coins needed to get `sum`
a denomination is canonical if, for each sum, dp[sum - max] + 1 == dp[sum]

* compute dp in O(N * MAX)
* check if it is canonical in O(MAX)
total time complexity O(N * MAX)

*/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<int> c(n);
  for (int& i : c) {
    cin >> i;
  }
  const int MAX = 1e6 + 42;
  const int INF = 1e9;
  vector<int> dp(2 * MAX, INF);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = c[i]; j < 2*MAX; ++j) {
      dp[j] = min(dp[j], 1 + dp[j - c[i]]);
    }
  }
  bool canonical = true;
  for (int i = c[0]; i < 2*MAX; ++i) {
    auto it = upper_bound(c.begin(), c.end(), i);
    --it;
    if (dp[i] < dp[i - *it] + 1) {
      canonical = false;
    }
  }
  cout << (canonical ? "canonical" : "non-canonical") << "\n";
}
