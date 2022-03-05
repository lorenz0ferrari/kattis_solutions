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

struct Line {
  pt a, b;
  Line() {}
  Line(pt _a, pt _b) : a(_a), b(_b) {}
};
istream& operator >>(istream &is, Line &A) { return is >> A.a >> A.b; }

pt operator +(const pt& A, const pt& B) { return pt(A.x + B.x, A.y + B.y); }
pt operator -(const pt& A, const pt& B) { return pt(A.x - B.x, A.y - B.y); }
pt_t operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }
bool operator ==(pt A, pt B) { return A.x == B.x && A.y == B.y; }

int sgn(LL x) {
  return (x > 0) - (x < 0);
}

bool intersect(Line r, Line s) {
  if (sgn((r.a-s.a)^(r.b-s.a)) == sgn((r.a-s.b)^(r.b-s.b))) return false;
  if (sgn((s.a-r.a)^(s.b-r.a)) == sgn((s.a-r.b)^(s.b-r.b))) return false;
  return true;
}

int calc_for_component(vector<Line> v) {
  int n = v.size();
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      cnt += intersect(v[i], v[j]);
    }
  }
  // Euler Formula: V + F - E = 2
  LL V = cnt + 2*n;
  LL E = 2*cnt + n;
  LL F = 2 + E - V;
  LL ans = F - 1;
  return ans;
}

struct Dsu {
  int n;
  vector<int> p;
  Dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  int findset(int v) {
    return v == p[v] ? v : p[v] = findset(p[v]);
  }
  bool onion(int a, int b) {
    a = findset(a);
    b = findset(b);
    p[b] = a;
    return a != b;
  }
  vector<vector<int>> get_components() {
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) mp[findset(i)].push_back(i);
    vector<vector<int>> ans;
    for (auto& [a, b] : mp) {
      ans.push_back(b);
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
  Dsu dsu(n);
  vector<Line> lines(n);
  for (auto& l : lines) {
    cin >> l;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (intersect(lines[i], lines[j])) {
        dsu.onion(i, j);
      }
    }
  }
  auto cc = dsu.get_components();
  int ans = 0;
  for (auto& c : cc) {
    vector<Line> l;
    for (int i : c) {
      l.push_back(lines[i]);
    }
    ans += calc_for_component(l);
  }
  cout << ans << "\n";
}
