#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;

int64_t fexp(int64_t x, int64_t y, int64_t mod) {
  int64_t ans = 1;

  while (y) {
    if (y & 1)
      ans = (ans * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }

  return ans;
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void solve() {
  int64_t n;
  int64_t e;

  cin >> n >> e;

  int64_t p = phi(n);

  cout << fexp(e, phi(p) - 1, p) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

}
