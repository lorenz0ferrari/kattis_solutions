#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int caso = 1; caso <= t; caso++) {
    cout << "Case #" << caso << ": ";

    int n;
    cin >> n;

    vector <int64_t> x(n);
    vector <int64_t> y(n);

    for (int64_t &i : x) cin >> i;
    for (int64_t &i : y) cin >> i;

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
      ans += x[i] * y[n - i - 1];
    }

    cout << ans << "\n";
  }
}
