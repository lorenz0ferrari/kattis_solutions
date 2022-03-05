#include <bits/stdc++.h>
using namespace std;
using LL = long long;

using pt_t = LL;
struct pt {
	pt_t x, y;
	pt() : x(0), y(0) {}
	pt(pt_t x, pt_t y) : x(x), y(y) {}
	double norm() const { return sqrt(x*x + y*y); }
};
istream& operator >>(istream &is, pt &A) { return is >> A.x >> A.y; }
ostream& operator <<(ostream &os, const pt &A) { return os << A.x << ' ' << A.y; }

pt operator +(const pt& A, const pt& B) { return pt(A.x + B.x, A.y + B.y); }
pt operator -(const pt& A, const pt& B) { return pt(A.x - B.x, A.y - B.y); }
pt_t operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }
bool operator ==(pt A, pt B) { return A.x == B.x && A.y == B.y; }
// if pt_t = double, (A-B) < EPS

const double PI = acos(0);

double angle(const pt& A, const pt& B) {
  return acos(double(A.x*B.x + A.y*B.y) / (A.norm() * B.norm()));
}
double angle(const pt& A, const pt& B, const pt& C) {
  double ans = angle(A-B, C-B);
  assert(ans >= 0);
  if (ans < 0) ans = PI - ans;
  return ans;
}

void cut(vector<pt>& P) {
  int n = P.size();
  if (n <= 3) return;
  auto ang = [&](int i) -> double {
    return angle(P[(i-1+n)%n], P[i], P[(i+1)%n]);
  };
  auto cuttable = [&](int i) -> bool {
    pt a = P[(i-2+n)%n];
    pt b = P[(i-1+n)%n];
    pt c = P[i];
    pt d = P[(i+1)%n];
    pt e = P[(i+2)%n];

    double C = angle(b, c, d);
    double B = angle(a, b, d);
    double D = angle(b, d, e);

    return C < min(B, D);
  };
  int sharpest = 0;
  for (int i = 1; i < n; ++i) {
    if (ang(i) < ang(sharpest)) {
      sharpest = i;
    }
  }
  if (cuttable(sharpest)) {
    cerr << sharpest << "\n";
    P.erase(P.begin() + sharpest);
  }
}

void solve(int n) {
  vector<pt> P(n);
  for (pt& i : P) cin >> i;
  for (int i = 0; i < 20; ++i) cut(P);
  cout << P.size() << " ";
  for (pt& i : P) cout << i << " ";
  cout << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  while (cin >> n) {
    if (n) solve(n);
    cerr << "\n";
  }
}
