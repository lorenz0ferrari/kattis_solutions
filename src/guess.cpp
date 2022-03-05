#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
  cout << x << endl;
  string s; cin >> s;
  return (s == "higher") - (s == "lower");
}

int main() {
  int l = 1, r = 1000;
  while (l <= r) {
    int m = (l + r) / 2;
    int res = ask(m);
    if (res == 0) return 0;
    if (res == 1) l = m + 1;
    if (res == -1) r = m - 1;
  }
}
