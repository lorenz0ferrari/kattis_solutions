#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<array<int, 2>> v(n);
    for (auto& [a, b] : v) {
      cin >> a >> b; --a;
      swap(a, b);
    }
    sort(v.begin(), v.end());
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, v[i][1] - i);
    }
    cout << mx << "\n";
}
