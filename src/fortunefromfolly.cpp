#include <bits/stdc++.h>
using namespace std;

using matrix_t = double;
struct Matrix {
  int n, m;
  vector<vector<matrix_t>> a;
  Matrix(int n, int m) : n(n), m(m) {
    a.assign(n, vector<matrix_t>(m, 0));
  }
  inline Matrix operator*(const Matrix other) const {
    assert(m == other.n);
    Matrix ans(n, other.m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < other.m; ++j) {
        for (int k = 0; k < m; ++k) {
          ans.a[i][j] += a[i][k] * other.a[k][j];
        }
      }
    }
    return ans;
  }
};
inline Matrix matrix_exp(Matrix x, int y) {
  assert(x.n == x.m);
  Matrix ans(x.n, x.n);
  for (int i = 0; i < x.n; ++i) ans.a[i][i] = 1;
  while (y) {
    if (y & 1) {
      ans = ans * x;
    }
    x = x * x;
    y >>= 1;
  }
  return ans;
}

int main() {
  int n; cin >> n;
  int k; cin >> k;
  double p; cin >> p;
  Matrix chain(1 << n, 1 << n);
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (__builtin_popcount(mask) >= k) continue;
    chain.a[mask][mask >> 1] = 1-p;
    chain.a[mask][mask >> 1 | (1 << (n-1))] = p;
  }

  vector<double> E(1 << n, 0);
  vector<double> found(1 << n, 1);
  double steps = 1;
  for (int start = 0; start < (1 << n); ++start) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (__builtin_popcount(mask) != k) continue;
      E[start] += steps * chain.a[start][mask];
    }
  }
  while (steps < 1e18) {
    found.assign(1 << n, 1);
    for (int start = 0; start < (1 << n); ++start) {
      for (int mask = 0; mask < (1 << n); ++mask) {
        found[start] -= chain.a[start][mask];
      }
    }
    auto newE = E;
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (__builtin_popcount(mask) >= k) continue;
      for (int nxt = 0; nxt < (1 << n); ++nxt) {
        newE[mask] += (E[nxt] + found[nxt] * steps) * chain.a[mask][nxt];
      }
    }
    chain = chain * chain;
    E = newE;
    steps = 2 * steps;
  }
  cout << fixed << setprecision(16) << E[0] - 1 << "\n";
}
