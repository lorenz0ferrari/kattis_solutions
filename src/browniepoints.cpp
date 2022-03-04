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
LL operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }
bool operator ==(pt A, pt B) { return A.x == B.x && A.y == B.y; }

void solve(int n) {
  vector<pt> P(n);
  for (pt& i : P) cin >> i;
  pt P0 = P[n / 2];
  for (pt& i : P) i = i - P0;
  int stan = 0;
  int ollie = 0;
  for (int i = 0; i < n; ++i) {
    stan += P[i].x * P[i].y > 0;
    ollie += P[i].x * P[i].y < 0;
  }
  cout << stan << " " << ollie << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  while (cin >> n) {
    if (n) solve(n);
  }
}
