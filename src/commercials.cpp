#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, p;
  cin >> n >> p;
  vector<LL> a(n);
  for (auto& i : a) {
    cin >> i;
    i -= p;
  }
  LL ans = 0;
  LL mn = 0;
  LL prf = 0;
  for (int i = 0; i < n; ++i) {
    prf += a[i];
    mn = min(mn, prf);
    ans = max(ans, prf - mn);
  }
  cout << ans << "\n";
}

