#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;

vector<bool> vis;
vector<vector<int>> g;

void dfs(int v) {
  vis[v] = true;
  for (int u : g[v])
    if (!vis[u])
      dfs(u);
}

void solve() {
  int n, m;
  cin >> n >> m;

  vis.assign(n, false);
  g.assign(n, vector<int> (0));

  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << i+1 << "\n";
      ans++;
    }
  }

  if (!ans)
    cout << "Connected" << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
