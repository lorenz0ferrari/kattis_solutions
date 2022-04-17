#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<int> jj(t+1, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = t; j >= v[i]; --j) {
      if (jj[j] != -1) continue;
      if (j == v[i] || jj[j - v[i]] != -1) {
        jj[j] = i;
      }
    }
  }
  int mx = t;
  while (mx && jj[mx] == -1) --mx;
  vector<bool> g(n);
  for (; jj[mx] != -1; mx -= v[jj[mx]]) {
    g[jj[mx]] = true;
  }
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; ++i) {
    if (g[i]) {
      cout << a << " ";
      a += v[i];
    } else {
      cout << b << " ";
      b += v[i];
    }
  }
}
