#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define F first
#define S second

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int k; cin >> k;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].F >> v[i].S;
  }
  sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
    return a.S < b.S;
  });
  multiset<int> rooms;
  for (int i = 0; i < k; ++i) rooms.insert(0);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto it = rooms.upper_bound(-v[i].F);
    if (it != rooms.end()) {
      ++ans;
      rooms.erase(it);
      rooms.insert(-v[i].S);
    }
  }
  cout << ans << "\n";
}
