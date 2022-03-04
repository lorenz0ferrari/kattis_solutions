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
  pt g; cin >> g;
  pt p1; cin >> p1;
  pt p2; cin >> p2;
  g = g - p1;
  p2 = p2 - p1;
  p1 = p1 - p1; // 0
  double ans = 1e9;
  ans = min(ans, g.norm());
  ans = min(ans, (p2 - g).norm());
  ans = min(ans, (pt(0,p2.y) - g).norm());
  ans = min(ans, (pt(p2.x,0) - g).norm());
  if (0 <= g.y && g.y <= p2.y) ans = min(ans, (double)min(abs(g.x), abs(g.x-p2.x)));
  if (0 <= g.x && g.x <= p2.x) ans = min(ans, (double)min(abs(g.y), abs(g.y-p2.y)));
  cout << fixed << setprecision(6) << ans << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
}
