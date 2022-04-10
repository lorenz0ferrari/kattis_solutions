#include <bits/stdc++.h>
using namespace std;

struct Lca {
  const int L = 20;
  int n;
  vector<int> dep;
  vector<vector<int>> up;
  Lca(int _n, vector<int> p) : n(_n) {
    dep.assign(n, 0);
    up.assign(n, vector<int>(L, -1));
    for (int i = 0; i < n; ++i) up[i][0] = p[i];
    for (int i = 1; i < L; ++i) {
      for (int j = 0; j < n; ++j) {
        if (up[j][i-1] == -1) up[j][i] = -1;
        else up[j][i] = up[up[j][i-1]][i-1];
      }
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
      if (p[i] == -1) continue;
      adj[p[i]].push_back(i);
    }
    auto dfs = [&](auto&& self, int v, int p) -> void {
      for (int u : adj[v]) {
        if (u == p) continue;
        dep[u] = dep[v] + 1;
        self(self, u, v);
      }
    };
    dfs(dfs, 0, -1);
  }
  int lift(int v, int k) {
    for (int i = L-1; v != -1 && i >= 0; --i) {
      if (k >= (1 << i)) {
        v = up[v][i];
        k -= 1 << i;
      }
    }
    return v;
  }
  int lca(int a, int b) {
    if (dep[a] > dep[b]) a = lift(a, dep[a] - dep[b]);
    if (dep[b] > dep[a]) b = lift(b, dep[b] - dep[a]);
    for (int i = L-1; i >= 0; --i) {
      if (up[a][i] != up[b][i]) {
        a = up[a][i];
        b = up[b][i];
      }
    }
    if (a == b) return a;
    return up[a][0];
  }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m; cin >> m;
  int k; cin >> k;
  vector<vector<int>> adj(n);
  vector<array<int, 2>> e(n-1);
  for (auto& [a, b] : e) {
    cin >> a >> b; --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> p(n, -1);
  auto dfs = [&](auto&& self, int v) -> void {
    for (auto u : adj[v]) {
      if (u == p[v]) continue;
      p[u] = v;
      self(self, u);
    }
  };
  dfs(dfs, 0);
  Lca bl(n, p);
  vector<vector<array<int, 2>>> upd(n);
  for (int i = 0; i < m; ++i) {
    int s; cin >> s;
    vector<int> ss(s);
    for (int& a : ss) {
      cin >> a; --a;
    }
    int lca = bl.lca(ss[0], ss[1]);
    for (int a : ss) lca = bl.lca(lca, a);
    for (int a : ss) if (a != lca) upd[a].push_back({i, 1});
    upd[lca].push_back({i, 0});
  }
  vector<int> cnt(n);
  auto solve = [&](auto&& self, int v) -> set<int> {
    set<int> s;
    for (int u : adj[v]) {
      if (u == p[v]) continue;
      auto ss = self(self, u);
      if (ss.size() > s.size()) swap(s,ss);
      for (int i : ss) s.insert(i);
    }
    for (auto [a, b] : upd[v]) {
      if (b) s.insert(a);
      else s.erase(a);
    }
    cnt[v] = s.size();
    return s;
  };
  solve(solve, 0);
  vector<int> ans;
  for (int i = 0; i < n-1; ++i) {
    if (p[e[i][0]] == e[i][1] && cnt[e[i][0]] >= k) ans.push_back(i+1);
    if (p[e[i][1]] == e[i][0] && cnt[e[i][1]] >= k) ans.push_back(i+1);
  }
  cout << ans.size() << "\n";
  for (int i : ans) cout << i << " ";
  cout << "\n";
}
