#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct pt {
	LL x, y;
	pt(): x(0), y(0) {}
	pt(LL x, LL y): x(x), y(y) {}
	double norm() { return sqrt(x*x + y*y); }
};
istream& operator >>(istream &in, pt &A) { return in >> A.x >> A.y; }
ostream& operator <<(ostream &out, const pt &A) { return out << '(' << A.x << ',' << A.y << ')'; }

pt operator +(const pt &A, const pt &B) { return pt(A.x + B.x, A.y + B.y); }
pt operator -(const pt &A, const pt &B) { return pt(A.x - B.x, A.y - B.y); }
double operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }
bool operator ==(pt A, pt B) { return A.x == B.x && A.y == B.y; }

void solve() {
  vector<pt> P(9);
  for (int i = 0; i < 9; ++i) {
    int o; cin >> o;
    P[o-1] = pt(i/3, i%3);
  }
  double ans = 0;
  for (int i = 1; i < 9; ++i) ans += (P[i]-P[i-1]).norm();
  cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
}
