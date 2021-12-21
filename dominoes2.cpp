#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void dfs(int v, vector<vector<int>>& g, vector<bool>& vis) {
  vis[v] = true;
  for (int u : g[v])
    if (!vis[u])
      dfs(u, g, vis);
}

void solve() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<bool> vis(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
  }
  for (int i = 0, a; i < l; ++i) {
    cin >> a;
    dfs(a, g, vis);
  }
  int cnt = 0;
  for (bool x : vis)
    cnt += x;
  cout << cnt << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--)
    solve();
}
