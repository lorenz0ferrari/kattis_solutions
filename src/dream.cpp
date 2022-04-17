#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  map<string, int> e;
  vector<string> ve;
  for (int i = 0; i < n; ++i) {
    char c; cin >> c;
    if (c == 'E') {
      string s; cin >> s;
      e[s] = e.size();
      ve.push_back(s);
    } else if (c == 'D') {
      int k; cin >> k;
      while (k--) {
        e.erase(ve.back());
        ve.pop_back();
      }
    } else if (c == 'S') {
      int k; cin >> k;
      bool works = true;
      int min_wrong = 1e9;
      int max_right = -1e9;
      while (k--) {
        string s; cin >> s;
        if (s[0] == '!') {
          if (e.find(s.substr(1)) == e.end()) continue;
          min_wrong = min(min_wrong, e[s.substr(1)]);
        } else if (e.find(s) == e.end()) {
          works = false;
        } else {
          max_right = max(max_right, e[s]);
        }
      }
      if (!works) {
        cout << "Plot Error\n";
      } else if (min_wrong == 1e9) {
        cout << "Yes\n";
      } else if (max_right < min_wrong) {
        cout << e.size() - min_wrong << " Just A Dream\n";
      } else {
        cout << "Plot Error\n";
      }
    }
  }
}
