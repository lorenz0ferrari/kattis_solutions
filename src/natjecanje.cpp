#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int s; cin >> s;
  int r; cin >> r;
  vector<int> v(n, 1);
  for (int i = 0; i < s; ++i) {
    int d; cin >> d; --d;
    --v[d];
  }
  for (int i = 0; i < r; ++i) {
    int d; cin >> d; --d;
    ++v[d];
  }
  for (int i = 0; i < n; ++i) {
    if (i && v[i] >= 2 && v[i-1] == 0) {
      --v[i]; ++v[i-1];
    }
    if (i+1<n && v[i] >= 2 && v[i+1] == 0) {
      --v[i]; ++v[i+1];
    }
  }
  int cnt = 0;
  for (int i : v) cnt += (i == 0);
  cout << cnt << "\n";
}
