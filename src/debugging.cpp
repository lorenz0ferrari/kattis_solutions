#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  LL n; cin >> n;
  LL r; cin >> r;
  LL p; cin >> p;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  auto works = [](LL N, LL R, LL P) -> bool {
    LL ans = 1;
    auto fexp = [&](LL x, LL y) -> void {
      while (y) {
        if (y & 1) {
          ans = ans * x;
        }
        if (ans >= N || x >= N) {
          ans = N;
          return;
        }
        x = x * x;
        y >>= 1;
      }
    };
    fexp(P / R + 2, P % R);
    fexp(P / R + 1, R - P % R);
    return ans >= N;
  };
  LL ans = 1e18;
  for (LL rs = 1; rs <= 20; ++rs) {
    LL low = 0, high = n;
    while (high - low > 1) {
      LL mid = (high + low) / 2;
      if (works(n, rs, mid))
        high = mid;
      else
        low = mid;
    }
    ans = min(ans, rs * r + high * p);
  }
  cout << ans << "\n";
}
