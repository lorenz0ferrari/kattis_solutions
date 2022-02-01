#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define F first
#define S second

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<pair<LL,LL>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].F >> v[i].S;
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n;) {
    ++ans;
    LL maxl = 0, minr = 1e9;
    while (i < n) {
      maxl = max(maxl, v[i].F);
      minr = min(minr, v[i].S);
      if (maxl > minr) break;
      ++i;
    }
  }
  cout << ans << "\n";
}

