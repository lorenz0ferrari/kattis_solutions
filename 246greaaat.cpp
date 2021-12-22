#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int t; cin >> t;
  vector<int> d(n + 1);
  vector<int> s(n + 1);
  d[0] = s[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i] >> d[i];
  }
  vector<int> dst(2 * t + 1, 1e9);
  vector<int> lst(2 * t + 1, -1);
  auto print = [&]() {
    vector<int> ans;
    for (int i = t; lst[i] != -1; i -= s[lst[i]]) {
      ans.push_back(lst[i]);
    }
    cout << ans.size() << "\n";
    for (int i : ans)
      cout << i+1 << " ";
    cout << "\n";
    exit(0);
  };
  vector<queue<int>> Q(t + 1);
  Q[0].push(0);
  dst[0] = 0; lst[0] = -1;
  for (int w = 0; w <= t; ++w) {
    while (!Q[w].empty()) {
      int v = Q[w].front();
      Q[w].pop();
      if (v == t) print();
      if (w > dst[v]) continue;
      for (int i = 0; i <= n; ++i) {
        int u = v + s[i];
        if (u < 0 || u > 2 * t || dst[u] <= w + d[i] || w + d[i] > t) continue;
        dst[u] = w + d[i];
        lst[u] = i;
        Q[dst[u]].push(u);
      }
    }
  }
}
