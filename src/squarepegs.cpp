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
  int k; cin >> k;
  vector<int> plots(n);
  for (int i = 0, r; i < n; ++i) {
    cin >> r;
    plots[i] = 4*r*r;
  }
  vector<int> houses(m + k);
  for (int i = 0, r; i < m; ++i) {
    cin >> r;
    houses[i] = 4*r*r;
  }
  for (int i = m, l; i < m+k; ++i) {
    cin >> l;
    houses[i] = 2*l*l;
  }
  sort(plots.begin(), plots.end());
  sort(houses.begin(), houses.end());
  int ans = 0;
  for (int i = 0, j = 0; i < m+k && j < n; ++i) {
    while (j < n && plots[j] <= houses[i]) ++j;
    ans += (j++ != n);
  }
  cout << ans << "\n";
}
