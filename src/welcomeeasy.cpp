#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const string target = "welcome to code jam";
const int L = target.size();
constexpr int mod = 10000;

void solve() {
  string s; getline(cin, s);
  vector<int> dp(L + 1); // dp[i] = in quanti modi posso fare target[:i]
  dp[0] = 1;
  for (char c : s) {
    auto prv = dp;
    for (int i = L; i > 0; --i) {
      if (c == target[i-1]) dp[i] = (prv[i] + prv[i-1]) % mod;
      else dp[i] = prv[i];
    }
  }
  string ss = to_string(dp[L]);
  while (ss.size() != 4) ss = "0" + ss;
  cout << ss << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t; string _; getline(cin, _);
  for (int tc = 1; tc <= t; ++tc) {
    cout << "Case #" << tc << ": ";
    solve();
  }
}
