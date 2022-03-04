#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct pt {
	double x, y;
	pt(): x(0), y(0) {}
	pt(double x, double y): x(x), y(y) {}
	double norm() { return sqrt(x*x + y*y); }
};
istream& operator >>(istream &in, pt &A) { return in >> A.x >> A.y; }
ostream& operator <<(ostream &out, const pt &A) { return out << '(' << A.x << ',' << A.y << ')'; }

pt operator +(const pt &A, const pt &B) { return pt(A.x + B.x, A.y + B.y); }
pt operator -(const pt &A, const pt &B) { return pt(A.x - B.x, A.y - B.y); }
double operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }
bool operator ==(pt A, pt B) { return A.x == B.x && A.y == B.y; }

const LL radius = 8;

void solve() {
  pt P0; cin >> P0;
  int n; cin >> n;
  bool found = false;
  for (int i = 0; i < n; ++i) {
    pt P; cin >> P;
    P = P - P0;
    if (P.x*P.x + P.y*P.y <= radius * radius) found = true;
  }
  cout << (found ? "light a candle" : "curse the darkness") << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
