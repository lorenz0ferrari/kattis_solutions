#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL M = 30;
const LL MOD = 1e9 + 7;

LL fxp(LL x, LL y) {
  LL ans = 1;
  while (y) {
    if (y & 1)
      ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}
LL inv(LL x) { return fxp(x, MOD-2); }

LL f[M + 1];

void solve() {
  int m; cin >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  int n; cin >> n;
  int t; cin >> t;
  unordered_map<int, int> frq[M/2 + 1];
  int sz1 = m / 2;
  int sz2 = m - m / 2;
  for (int mask = 0; mask < (1 << sz1); ++mask) {
    int sum = 0;
    for (int i = 0; i < sz1; ++i) {
      if (mask & (1 << i)) {
        sum += a[i];
      }
    }
    ++frq[__builtin_popcount(mask)][sum];
  }
  LL ans = 0;
  for (int mask = 0; mask < (1 << sz2); ++mask) {
    int sum = 0;
    for (int i = 0; i < sz2; ++i) {
      if (mask & (1 << i)) {
        sum += a[sz1 + i];
      }
    }
    int other = n - __builtin_popcount(mask);
    if (0 <= other && other <= sz1) {
      ans += frq[other][t - sum];
    }
  }
  LL choose = f[m] * inv(f[n])  % MOD * inv(f[m - n]) % MOD;
  cout << ans << " : " << choose-ans << "\n";
}

int main() {
  f[0] = 1;
  for (int i = 1; i <= M; ++i) {
    f[i] = f[i - 1] * i % MOD;
  }
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Game " << i << " -- ";
    solve();
  }
}
