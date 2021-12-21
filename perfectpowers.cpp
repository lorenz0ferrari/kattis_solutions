#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(LL n) {
  bool neg = (n < 0);
  n = abs(n);
  LL ans = 0;
  for (LL i = 2; i*i <= n; ++i) {
    if (n % i) continue;
    LL cnt = 0;
    for (; n % i == 0; n /= i, ++cnt);
    ans = __gcd(ans, cnt);
  }
  if (n != 1) ans = 1;
  if (neg && ans)
    while (!(ans & 1))
      ans >>= 1;
  cout << max(ans, 1LL) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (LL x; cin >> x;) {
    if (!x) break;
    solve(x);
  }
}
