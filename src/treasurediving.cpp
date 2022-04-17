#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<int> dist(int s, const vector<vector<array<int, 2>>>& adj) {
  vector<int> d(adj.size(), 1e9); d[s] = 0;
  priority_queue<array<int, 2>> Q; Q.push({0, s});
  while (!Q.empty()) {
    auto [td, v] = Q.top();
    Q.pop();
    if (-td > d[v]) continue;
    for (auto [u, w] : adj[v]) {
      if (d[u] > d[v] + w) {
        d[u] = d[v] + w;
        Q.push({-d[u], u});
      }
    }
  }
  return d;
}

void solve() {
  int n; cin >> n;
  int m; cin >> m;
  vector<vector<array<int, 2>>> adj(n);
  for (int i = 0, a, b, c; i < m; ++i) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  int ii; cin >> ii;
  vector<int> v(ii);
  for (int i = 0; i < ii; ++i) {
    cin >> v[i];
  }
  int air; cin >> air;
  vector<int> d0 = dist(0, adj);
  vector<vector<int>> di;
  for (int i = 0; i < ii; ++i) {
    di.push_back(dist(v[i], adj));
  }
  int ans = 0;
  for (int mask = 1; mask < (1 << ii); ++mask) {
    vector<int> p;
    for (int i = 0; i < ii; ++i) {
      if (mask & (1 << i)) {
        p.push_back(i);
      }
    }
    do {
      LL tot = 0;
      tot += d0[v[p[0]]] + d0[v[p.back()]];
      for (int i = 1; i < int(p.size()); ++i) {
        tot += di[p[i-1]][v[p[i]]];
      }
      if (tot <= air) {
        ans = max(ans, int(p.size()));
      }
    } while (next_permutation(p.begin(), p.end()));
  }
  cout << ans << "\n";
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
