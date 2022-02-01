#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(3*n);
    for (int i = 0; i < 3*n; ++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += v[3*n - 2*(i+1)];
    }
    cout << ans << "\n";
  }
}

