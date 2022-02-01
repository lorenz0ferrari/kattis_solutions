#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<int> adj;
vector<int> area;

struct solution {
  int n;
  int ans = 0;
  int sum_left = 0;
  int current_sum = 0;
  vector<int> mask;
  solution(int _n) : n(_n) {
    for (int i = 0; i < n; ++i) sum_left += area[i];
    mask.push_back(0);
    rec(0);
  }
  void rec(int i) {
    if (__builtin_popcount(mask.back()) == n) {
      ans = max(ans, current_sum);
      return;
    }
    if (current_sum + sum_left <= ans) return;
    sum_left -= area[i];
    if (!(mask.back() & (1 << i))) {
      current_sum += area[i];
      mask.push_back(mask.back() | adj[i]);
      rec(i+1);
      current_sum -= area[i];
      mask.pop_back();
    }
    rec(i+1);
    sum_left += area[i];
  }
  int getans() const { return ans; }
};

void solve(int n) {
  area.assign(n, -1);
  adj.assign(n, 0);
  vector<array<int, 4>> v(n);
  for (auto& [w, h, x, y] : v) {
    cin >> w >> h >> x >> y;
  }
  sort(v.begin(), v.end(), [](array<int,4> a, array<int,4> b){
    return a[0]*a[1] > b[0]*b[1];
  });
  for (int i = 0; i < n; ++i) area[i] = v[i][0] * v[i][1];
  auto overlap = [&](int i, int j) -> bool {
    // Is the area of the intersection > 0
    int lx = max(v[i][2], v[j][2]);
    int ly = max(v[i][3], v[j][3]);
    int rx = min(v[i][2] + v[i][0], v[j][2] + v[j][0]);
    int ry = min(v[i][3] + v[i][1], v[j][3] + v[j][1]);
    return lx < rx && ly < ry;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j || overlap(i, j)) {
        adj[i] |= 1 << j;
      }
    }
  }
  solution sol(n);
  cout << sol.getans() << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  while (cin >> n && n) {
    solve(n);
  }
}
