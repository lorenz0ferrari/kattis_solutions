#include <bits/stdc++.h>
using namespace std;
using LL = long long;

#define watch(x) cerr << (#x) << " is " << x << endl

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  LL n; cin >> n;
  LL k; cin >> k;
  LL q; cin >> q;
  auto pow = [&](LL k, LL y) -> LL {
    LL ans = 1;
    while (y--) ans *= k;
    return ans;
  };
  auto sum_of_pows = [&](LL k, LL i) -> LL {
    if (i < 0) return 0LL;
    return (pow(k, i+1) - 1) / (k - 1);
  };
  auto depth = [&](LL v) -> LL {
    LL ans = 0;
    LL acc = 1;
    while (acc < v) {
      acc = acc*k + 1;
      ++ans;
    }
    return ans;
  };
  auto node_to_position = [&](LL v) -> LL {
    return v - sum_of_pows(k, depth(v) - 1) - 1;
  };
  auto position_to_node = [&](LL pos, LL dep) -> LL {
    return sum_of_pows(k, dep-1) + pos + 1;
  };
  auto parent = [&](LL v) -> LL {
    if (v == 1) return -1;
    return position_to_node(node_to_position(v) / k, depth(v) - 1);
  };
  while (q--) {
    LL x; cin >> x;
    LL y; cin >> y;
    if (k == 1) {
      cout << abs(x - y) << "\n";
      continue;
    }
    LL ans = 0;
    LL dx = depth(x);
    LL dy = depth(y);
    while (dx > dy) {
      --dx; x = parent(x);
      ++ans;
    }
    while (dy > dx) {
      --dy; y = parent(y);
      ++ans;
    }
    while (y != x) {
      ans += 2;
      y = parent(y);
      x = parent(x);
    }
    cout << ans << "\n";
  }
}
