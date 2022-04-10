#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m; cin >> m;
  vector<map<int, int>> adj(n+1);
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    ++adj[a][b];
  }
  int w; cin >> w;
  vector<int> p(w+1);
  for (int& i : p) cin >> i;
  for (int i = 1; i <= w; ++i) {
    if (--adj[p[i-1]][p[i]] < 0) {
      cout << i << "\n";
      return 0;
    }
  }
  if (w != m) {
    cout << "too short" << "\n";
    return 0;
  }
  cout << "correct" << "\n";
}
