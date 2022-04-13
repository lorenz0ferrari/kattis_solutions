#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m, k, sa, sb;
  cin >> n >> m >> k >> sa >> sb; --sa; --sb;
  vector<vector<int>> adj(n);
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b; --a; --b;
    adj[a].push_back(b);
  }
  vector<int> val(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    int x; cin >> x;
    if (s == "TAX") val[i] = -x;
    if (s == "SALARY") val[i] = +x;
    if (s == "PROPERTY") { int _; cin >> _; }
    cerr << s << " " << x << endl;
  }
  vector<bool> vis(n);
  vector<LL> dp(n, -1e18);
  auto dfs = [&](auto&& self, int v) -> LL {
    if (vis[v]) return dp[v];
    if (adj[v].size() == 0) return dp[v] = 0;
    for (int u : adj[v]) {
      dp[v] = max(dp[v], val[u] + self(self, u));
    }
    vis[v] = true;
    return dp[v];
  };
  cout << dfs(dfs, sa) << " " << dfs(dfs,sb) << "\n";
}
