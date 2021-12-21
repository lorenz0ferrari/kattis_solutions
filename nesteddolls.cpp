#include <bits/stdc++.h>
using namespace std;

struct doll {
  int w{};
  int h{};
  doll(int _w, int _h) : w(_w), h(_h) {}
  doll() {}
};

void solve() {
  int m; cin >> m;
  vector<doll> v(m);
  for (int i = 0; i < m; ++i) {
    cin >> v[i].w >> v[i].h;
  }
  sort(v.begin(), v.end(), [](doll a, doll b) {
    if (a.w > b.w) return true;
    if (a.w < b.w) return false;
    return a.h < b.h;
  });
  vector<int> heaps; // greedy keep heaps like in lis
  for (auto [w, h] : v) {
    auto it = upper_bound(heaps.begin(), heaps.end(), h);
    if (it == heaps.end()) {
      heaps.push_back(h);
    } else {
      *it = h;
    }
  }
  cout << heaps.size() << "\n";
}

int main() {
  int t; cin >> t;
  while (t--)
    solve();
}
