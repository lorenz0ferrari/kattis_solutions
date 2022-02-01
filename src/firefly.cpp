#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define F first
#define S second

struct lazy_sum {
  int n;
  vector<int> prf;
  lazy_sum(int n) : n(n) {
    prf.assign(n, 0);
  }
  void upd(int i, int j, int val = 1) {
    prf[i] += val;
    if (j < n-1) prf[j + 1] -= val;
  }
  void compute() {
    for (int i = 1; i < n; ++i) {
      prf[i] += prf[i - 1];
    }
  }
  int operator[](int i) { return prf[i]; }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int h; cin >> h;
  lazy_sum v(h);
  for (int i = 0, a; i < n; ++i) {
    cin >> a;
    if (i & 1) v.upd(0, a-1);
    else v.upd(h-a, h-1);
  }
  v.compute();
  int mn = 1e9;
  int cnt = 0;
  for (int i = 0; i < h; ++i) mn = min(mn, v[i]);
  for (int i = 0; i < h; ++i) cnt += (v[i] == mn);
  cout << mn << " " << cnt << "\n";
}

