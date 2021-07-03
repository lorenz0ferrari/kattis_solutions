#include <bits/stdc++.h>
using namespace std;

int f(int a, int b) {
  return 100*a + b;
}

bool dfs(int v, int par, vector<vector<int>> &g, vector<bool> &vis) {
  if (vis[v])
    return true;
  vis[v] = true;
  for (int u : g[v])
    if (u != par && dfs(u,v,g,vis))
      return true;
  return false;
}

int main() {
  int a, b;
  cin >> a >> b;

  char grid[105][105] {};
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      cin >> grid[i][j];

  const int N = 15000;
  vector<bool> vis(N);
  vector<vector<int>> g(N);

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (grid[i][j] == '#') {
        int v = f(i, j);
        if (grid[i+1][j  ] == '#') { g[v].push_back(f(i+1,j  )); g[f(i+1,j  )].push_back(v); }
        if (grid[i+1][j-1] == '#') { g[v].push_back(f(i+1,j-1)); g[f(i+1,j-1)].push_back(v); }
        if (grid[i  ][j-1] == '#') { g[v].push_back(f(i  ,j-1)); g[f(i  ,j-1)].push_back(v); }
        if (grid[i-1][j-1] == '#') { g[v].push_back(f(i-1,j-1)); g[f(i-1,j-1)].push_back(v); }
        if (grid[i-1][j  ] == '#') { g[v].push_back(f(i-1,j  )); g[f(i-1,j  )].push_back(v); }
        if (grid[i-1][j+1] == '#') { g[v].push_back(f(i-1,j+1)); g[f(i-1,j+1)].push_back(v); }
        if (grid[i  ][j+1] == '#') { g[v].push_back(f(i  ,j+1)); g[f(i  ,j+1)].push_back(v); }
        if (grid[i+1][j+1] == '#') { g[v].push_back(f(i+1,j+1)); g[f(i+1,j+1)].push_back(v); }
      }
    }
  }

  int ans = 0;
  for (int i = 101; i <= 100*a + b; i++)
    if (!vis[i])
      ans += dfs(i, -1, g, vis);

  cout << ans << "\n";
}
