#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAX = 1001;
const int INF = 1e9;

struct state {
  int mnh = INF;
  char how = '*';
};

void solve() {
  int n; cin >> n;
  vector<int> d(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
  }
  vector<vector<state>> dp(MAX, vector<state>(n + 1));
  dp[0][0].mnh = 0;
  for (int i = 1; i <= n; ++i) {
    for (int h = 0; h < MAX; ++h) {
      // go down from up
      if (h + d[i] < MAX && dp[h + d[i]][i-1].mnh < dp[h][i].mnh) {
        dp[h][i].mnh = max(h + d[i], dp[h + d[i]][i-1].mnh);
        dp[h][i].how = 'D';
      }
      // go up from down
      if (h - d[i] >= 0 && dp[h - d[i]][i-1].mnh < dp[h][i].mnh) {
        dp[h][i].mnh = max(h, dp[h - d[i]][i-1].mnh);
        dp[h][i].how = 'U';
      }
    }
  }
  if (dp[0][n].mnh == INF) {
    cout << "IMPOSSIBLE" << "\n";
  } else {
    string ans = "";
    for (int i = n, h = 0; i > 0; --i) {
      ans.push_back(dp[h][i].how);
      if (dp[h][i].how == 'D') {
        h += d[i];
      } else {
        h -= d[i];
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
  }
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


