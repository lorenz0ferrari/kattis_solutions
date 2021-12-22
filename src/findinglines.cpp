#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct pt {
	LL x, y;
	pt(): x(0), y(0) {}
	pt(LL x, LL y): x(x), y(y) {}
};
istream& operator >>(istream &in, pt &A) { return in >> A.x >> A.y; }
pt operator -(const pt &A, const pt &B) { return pt(A.x - B.x, A.y - B.y); }
LL operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  mt19937 gen(time(0));
  int n; cin >> n;
  int p; cin >> p;
	vector<pt> P(n);
  for (pt &i : P) cin >> i;

  int k = (n * p + 99) / 100;
  if (n <= 2) {
    cout << "possible\n";
    return 0;
  }
  for (int i = 0; i < 500; ++i) {
    int a = gen() % n;
    int b = gen() % n;
    if (a == b) continue;
    int cnt = 0;
    for (int j = 0; j < n; ++j)
      cnt += (((P[a]-P[j]) ^ (P[b]-P[j])) == 0);
    if (cnt >= k) {
      cout << "possible\n";
      return 0;
    }
  }
  cout << "impossible\n";
}
