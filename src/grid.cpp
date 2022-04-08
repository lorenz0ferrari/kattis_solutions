#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> g(n, vector<int> (m));
    for (auto& x : g) for (auto& y : x) {
      char c; cin >> c;
      y = c-'0';
    }
    vector<vector<vector<array<int, 2>>>> adj(n, vector<vector<array<int, 2>>>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int k = g[i][j];
        if (i-k >= 0) adj[i][j].push_back({i-k, j});
        if (j-k >= 0) adj[i][j].push_back({i, j-k});
        if (i+k < n) adj[i][j].push_back({i+k, j});
        if (j+k < m) adj[i][j].push_back({i, j+k});
      }
    }
    vector<vector<int>> d(n, vector<int> (m, 1e9)); d[0][0] = 0;
    queue<array<int, 3>> Q; Q.push({0, 0, 0});
    while (!Q.empty()) {
      auto [td, i, j] = Q.front();
      Q.pop();
      for (auto [a, b] : adj[i][j]) {
        if (d[a][b] > d[i][j] + 1) {
          d[a][b] = d[i][j] + 1;
          Q.push({-d[a][b], a, b});
        }
      }
    }
    cout << (d[n-1][m-1] == 1e9 ? -1 : d[n-1][m-1]) << "\n";
}
