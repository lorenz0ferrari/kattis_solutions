#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<set<string>> s(n);
  for (int i = 0; i < k; ++i) {
    int j; cin >> j;
    string str; cin >> str;
    s[j].insert(str);
  }
  int m; cin >> m;
  vector<string> l(m);
  for (int i = 0; i < m; ++i)
    cin >> l[i];
  int r = 0;
  vector<int> wi(m);
  for (int i = 0; i < n; ++i) {
    while (r < m && s[i].find(l[r]) != s[i].end())
      wi[r++] = i;
  }
  if (r != m) {
    cout << "impossible" << "\n";
    return 0;
  }
  vector<int> we(m);
  --r;
  for (int i = n - 1; i >= 0; --i) {
    while (r >= 0 && s[i].find(l[r]) != s[i].end())
      we[r--] = i;
  }
  assert(r == -1);
  for (int i = 0; i < m; ++i) {
    if (wi[i] != we[i]) {
      cout << "ambiguous" << "\n";
      return 0;
    }
  }
  cout << "unique" << "\n";
}
