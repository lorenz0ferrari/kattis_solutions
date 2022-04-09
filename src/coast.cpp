#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m; cin >> m;
  vector<vector<int>> g(n+2, vector<int>(m+2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c; cin >> c;
      g[i][j] = c - '0';
    }
  }
  vector<vector<bool>> sea(n+2, vector<bool>(m+2));
  auto dfs = [&](auto&& self, int i, int j) -> void {
    if (i < 0 || i > n+1 || j < 0 || j > m+1) return;
    if (sea[i][j] || g[i][j] == 1) return;
    sea[i][j] = true;
    self(self, i-1, j);
    self(self, i+1, j);
    self(self, i, j-1);
    self(self, i, j+1);
  };
  dfs(dfs,0,0);
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] == 0) continue;
      ans += sea[i-1][j];
      ans += sea[i+1][j];
      ans += sea[i][j-1];
      ans += sea[i][j+1];
    }
  }
  cout << ans << "\n";
}
