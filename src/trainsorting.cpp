#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// max point-range segment tree
class segment {
public:
  int n;
  vector<int> t;
  segment(int n) : n(n) {
    t.resize(2 * n);
  }
  void upd(int p, int v) {
    for (t[p += n] = v; p > 1; p >>= 1) {
      t[p >> 1] = max(t[p], t[p ^ 1]);
    }
  }
  int qry(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = max(ans, t[l++]);
      if (r & 1) ans = max(ans, t[--r]);
    }
    return ans;
  }
};

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<int> w(n);
  for (int& i : w) cin >> i;
  vector<int> lis(n);
  vector<int> lds(n);
  const int W = 10005;
  segment low(W);
  segment high(W);
  for (int i = n-1; i >= 0; --i) {
    lis[i] = 1 + low.qry(w[i]+1, W);
    lds[i] = 1 + high.qry(0, w[i]);
    low.upd(w[i], lis[i]);
    high.upd(w[i], lds[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, lis[i] + lds[i] - 1);
  }
  cout << ans << "\n";
}
