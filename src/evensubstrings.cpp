#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int K = 6;

using ark = array<LL, 1 << K>;

struct nd {
// how many good substrings
// how many prefix/suffix for each combination
  LL val = -1;
  LL mask = 0;
  ark prf {};
  ark sff {};
  nd() {}
  nd(LL val, LL mask) : val(val), mask(mask) {
    ++prf[mask];
    ++sff[mask];
  }
  nd(LL val, LL mask, ark prf, ark sff) :
    val(val), mask(mask), prf(prf), sff(sff) {}
};
nd join(const nd& a, const nd& b) {
  if (b.val == -1) return a;
  if (a.val == -1) return b;
  LL nval = a.val + b.val;
  LL nmask = a.mask ^ b.mask;
  ark nprf {};
  ark nsff {};
  for (int i = 0; i < (1 << K); ++i) {
    nval += a.sff[i] * b.prf[i];
    nprf[i] = a.prf[i] + b.prf[a.mask ^ i];
    nsff[i] = b.sff[i] + a.sff[b.mask ^ i];
  }
  return nd(nval, nmask, nprf, nsff);
}

#ifdef LORENZO
constexpr int N = 1 << 3;
#else
constexpr int N = 1 << 18;
#endif

nd t[2 * N];

void update(int i, char c) {
  for (t[i += N] = nd(0, 1 << (c-'a')); i > 1; i >>= 1) {
    t[i >> 1] = (i & 1) ? join(t[i^1], t[i]) : join(t[i], t[i^1]);
  }
}

nd query(int i, int l, int r, int a, int b) {
  if (r <= a || b <= l) return nd();
  if (l <= a && b <= r) return t[i];
  int m = (a + b) / 2;
  return join(query(2*i, l, r, a, m), query(2*i+1, l, r, m, b));
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  int n; n = s.size();
  for (int i = 0; i < n; ++i) t[i + N] = nd(0, 1 << (s[i]-'a'));
  for (int i = n; i < N; ++i) t[i + N] = nd();
  for (int i = N-1; i > 0; --i) {
    t[i] = join(t[2*i], t[2*i + 1]);
  }
  int q; cin >> q;
  for (int type; q--;) {
    cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      cout << query(1, l-1, r, 0, N).val << "\n";
    } else {
      int i; cin >> i;
      char c; cin >> c;
      update(i-1, c);
    }
  }
}
