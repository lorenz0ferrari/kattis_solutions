#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  bitset<2000> ks; ks[0] = 1;
  for (int i = 0, a; i < n; ++i) {
    cin >> a;
    ks |= ks << a;
  }
  for (int d = 0; d < 1000; ++d) {
    if (ks[1000 + d]) {
      cout << 1000 + d << "\n";
      return 0;
    } else if (ks[1000 - d]) {
      cout << 1000 - d << "\n";
      return 0;
    }
  }
}
