#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL INF = 1.8e18;

struct Matrix {
  int n;
  int m;
  vector<vector<LL>> a;
  Matrix(int _n, int _m = -1) : n(_n), m(_m) {
    if (m == -1) m = n;
    a.assign(n, vector<LL>(m, 0));
  }
  void make_zero() {
    a.assign(n, vector<LL>(m, 0));
  }
  void make_inf() {
    a.assign(n, vector<LL>(m, 1e9));
  }
  Matrix operator*(const Matrix other) const {
    assert(m == other.n);
    Matrix ans(n, other.m); ans.make_inf();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < other.m; ++j) {
        for (int k = 0; k < m; ++k) {
          ans.a[i][j] = min(ans.a[i][j], a[i][k] + other.a[k][j]);
        }
      }
    }
    return ans;
  }
  Matrix operator^(const Matrix other) const {
    assert(m == other.n);
    Matrix ans(n, other.m); ans.make_zero();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < other.m; ++j) {
        for (int k = 0; k < m; ++k) {
          ans.a[i][j] = max(ans.a[i][j], a[i][k] + other.a[k][j]);
        }
      }
    }
    return ans;
  }
};
Matrix mat_exp(Matrix base, LL y, bool which) {
  assert(base.n == base.m);
  Matrix ans(base.n);
  while (y) {
    if (y & 1) ans = which ? base*ans : base^ans;
    y >>= 1;
    base = which ? base * base : base ^ base;
  }
  return ans;
}

void solve(int n) {
  Matrix m(n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    cin >> m.a[i][j];
  }
  int k; cin >> k;
  auto mx = mat_exp(m, k, 0);
  auto mn = mat_exp(m, k, 1);
  int a = 0;
  int b = 1e9;
  for (int i = 0; i < n; ++i) {
    a = max((LL)a, mx.a[0][i]);
    b = min((LL)b, mn.a[0][i]);
  }
  cout << a << " " << b << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  while (cin >> n && n) {
    solve(n);
  }
}
