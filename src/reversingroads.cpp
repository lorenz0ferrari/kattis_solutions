#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool test(int n, const vector<set<int>>& adj) {
  vector<bool> vis(n, false);
  auto dfs = [&vis](auto&& self, int v, const vector<set<int>>& adj) -> void {
    if (vis[v]) return;
    vis[v] = true;
    for (auto u : adj[v]) {
      self(self, u, adj);
    }
  };
  dfs(dfs, 0, adj);
  for (int i = 0; i < n; ++i) if (!vis[i]) return false;
  vis.assign(n, false);
  vector<set<int>> rev(n);
  for (int i = 0; i < n; ++i) {
    for (int j : adj[i]) {
      rev[j].insert(i);
    }
  }
  dfs(dfs, 0, rev);
  for (int i = 0; i < n; ++i) if (!vis[i]) return false;
  return true;
}

void solve(int n, int m) {
  vector<set<int>> adj(n);
  vector<array<int, 2>> e(m);
  for (auto& [a, b] : e) {
    cin >> a >> b;
    adj[a].insert(b);
  }
  if (test(n, adj)) {
    cout << "valid\n";
    return;
  }
  for (auto [a, b] : e) {
    adj[b].insert(a);
    adj[a].erase(b);
    if (test(n, adj)) {
      cout << a << " " << b << "\n";
      return;
    }
    adj[b].erase(a);
    adj[a].insert(b);
  }
  cout << "invalid\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  for (int tc = 1; cin >> n >> m; ++tc) {
    cout << "Case " << tc << ": ";
    solve(n, m);
  }
}
