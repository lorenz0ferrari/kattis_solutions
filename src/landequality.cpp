#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int> (m));
  array<int, 3> cnt{};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
      ++cnt[g[i][j]];
    }
  }
  if (cnt[0] >= 2) {
    cout << 0 << "\n";
  } else if (cnt[0] == 1) {
    if (n > 1 && m > 1) cout << 2 - bool(cnt[1] > 0) << "\n";
    else {
      if (n == 1) {
        int a = g[0][0];
        if (a == 0 || (g[0][m-1] != 0 && g[0][m-1] < a)) a = g[0][m-1];
        cout << a << "\n";
      } else {
        int a = g[0][0];
        if (a == 0 || (g[n-1][0] != 0 && g[n-1][0] < a)) a = g[n-1][0];
        cout << a << "\n";
      }
    }
  } else if (!(cnt[2] & 1)) {
    cout << 0 << "\n";
  } else {
    cout << (1ULL << (cnt[2] / 2)) << "\n";
  }
}
