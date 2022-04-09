#include <bits/stdc++.h>
using namespace std;
using LL = long long;


int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  deque<int> v;
  while (n) {
    v.push_front(n & 1);
    n >>= 1;
  }
  int ans = 0;
  for (int i = 0; i < int(v.size()); ++i) {
    ans += (1 << i) * v[i];
  }
  while (!(ans & 1)) ans >>= 1 ;
  cout << ans << "\n";
}
