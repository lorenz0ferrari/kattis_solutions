#include <bits/stdc++.h>
using namespace std;

int ans[101];
set <int> g[101];

inline bool dfs (int v) {
  bool can[5] {1,1,1,1,1};
  for (int u : g[v])
    can[ans[u]] = false;

  for (int i = 1; i <= 4; i++) {
    if (can[i]) {
      ans[v] = i;
      bool p = true;
      for (int u : g[v]) {
        if (!ans[u] && !dfs(u)) {
          p = false;
          break;
        }
      }

      if (p)
        return true;
    }
  }

  ans[v] = 0;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;

  int a, b;
  char dummy;
  while (cin >> a >> dummy >> b) {
    g[a].insert(b);
    g[b].insert(a);
  }

  for (int i = 1; i <= n; i++)
    if (!ans[i])
      assert(dfs(i));

  for (int i = 1; i <= n; i++)
    cout << i << " " << ans[i] << "\n";
}
