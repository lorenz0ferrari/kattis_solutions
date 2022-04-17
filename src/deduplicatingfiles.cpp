#include <bits/stdc++.h>
using namespace std;

int h(const string& s) {
  int ans = 0;
  for (char c : s) {
    ans ^= int(c);
  }
  return ans;
}

void solve(int n) {
  string s; getline(cin, s);
  set<string> st;
  vector<string> rec;
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    st.insert(s);
    rec.push_back(s);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      ans += (rec[i] != rec[j] && h(rec[i]) == h(rec[j]));
    }
  }
  cout << st.size() << " " << ans << "\n";
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  while (cin >> n && n) {
    solve(n);
  }
}
