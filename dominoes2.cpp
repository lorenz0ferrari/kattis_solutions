#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii;


vector<bool> vis;
vector<vector<int>> g;

void dfs(int v) {
  vis[v] = true;

  for (int u : g[v])
    if (!vis[u])
      dfs(u);
}

void solve() {
  int n, m, l;
  cin >> n >> m >> l;

  vis.assign(n+1, false);
  g.assign(n+1, vector<int> (0));

  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
  }

  for (int i = 0, a; i < l; i++) {
    cin >> a;
    dfs(a);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += vis[i];

  cout << ans << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
