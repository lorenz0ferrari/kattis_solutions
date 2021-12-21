#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<string> token(string s) {
  vector<string> ans;
  istringstream in(s);
  string t;
  while (getline(in, t, ' '))
    ans.push_back(t);
  return ans;
}

string lower(string s) {
  for (char& c : s)
    if ('A' <= c && c <= 'Z')
      c += 'a' - 'A';
  return s;
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  unordered_set<string> words;
  for (string s; getline(cin, s);) {
    auto l = token(s);
    for (auto w : l) {
      if (words.find(lower(w)) == words.end()) {
        cout << w << " ";
        words.insert(lower(w));
      } else {
        cout << "." << " ";
      }
    }
    cout << "\n";
  }
}
