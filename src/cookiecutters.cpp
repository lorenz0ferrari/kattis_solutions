#include <bits/stdc++.h>
using namespace std;
using LL = long long;

using pt_t = double;
struct pt {
	pt_t x, y;
	pt(): x(0), y(0) {}
	pt(pt_t x, pt_t y): x(x), y(y) {}
	double norm() { return sqrt(x*x + y*y); }
};
istream& operator >>(istream &in, pt &A) { return in >> A.x >> A.y; }
ostream& operator <<(ostream &out, const pt &A) { return out << A.x << ' ' << A.y; }

pt operator +(const pt& A, const pt &B) { return pt(A.x + B.x, A.y + B.y); }
pt operator -(const pt& A, const pt &B) { return pt(A.x - B.x, A.y - B.y); }
pt_t operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }
bool operator ==(pt A, pt B) { return A.x == B.x && A.y == B.y; } // if pt = LL

void solve() {
  int n; cin >> n;
  vector<pt> P(n);
  for (pt& i : P) cin >> i;
  double mx = 1e9, my = 1e9;
  for (pt& i : P) {
    mx = min(mx, i.x);
    my = min(my, i.y);
  }
  for (pt& i : P) i = i - pt(mx, my);
  double A = 0;
  for (int i = 1; i < n; ++i) A += (P[i]-P[0])^(P[(i+1)%n]-P[0]);
  if (A < 0) A = -A;
  A /= 2;
  double a; cin >> a;
  double ratio = sqrt(a/A);
  for (pt& i : P) {
    i.x *= ratio;
    i.y *= ratio;
  }
  for (pt& i : P) {
    cout << fixed << setprecision(9) << i << "\n";
  }
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
}
