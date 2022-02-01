#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector<LL> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  LL sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += v[i] << (n - 1);
  }
  const int W = 200;
  for (int i = 0; i < n; ++i) if (v[i] < W) sum -= v[i];
  for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) {
    if (v[i] + v[j] < W) {
      sum -= v[i] + v[j];
    }
  }
  for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) for (int k = j+1; k < n; ++k) {
    if (v[i] + v[j] + v[k] < W) {
      sum -= v[i] + v[j] + v[k];
    }
  }
  cout << sum << "\n";
}


