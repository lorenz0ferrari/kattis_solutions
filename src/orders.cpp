#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct state {
  int val = 0; // 0 = impossible, 1 = unique, 2 = ambiguous
  int last = -1;
  state() {}
};

const int S = 30042;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<int> c(n); // original set of prices
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector<state> dp(S + 1);
  dp[0].val = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= S; ++j) {
      if (c[i] > j) continue;
      if (dp[j - c[i]].val == 0) continue;
      if (dp[j - c[i]].val == 2) dp[j].val = 2;
      else if (dp[j].val != 0) dp[j].val = 2;
      else {
        dp[j].val = 1;
        dp[j].last = i;
      }
    }
  }
  int m; cin >> m;
  for (int test = 0; test < m; ++test) {
    int s; cin >> s;
    if (dp[s].val == 0) {
      cout << "Impossible" << "\n";
    } else if (dp[s].val == 2) {
      cout << "Ambiguous" << "\n";
    } else {
      vector<int> ans;
      while (s != 0) {
        int id = dp[s].last;
        s -= c[id];
        ans.push_back(id+1);
      }
      sort(ans.begin(), ans.end());
      for (int i : ans) cout << i << " ";
      cout << "\n";
    }
  }
}
