#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int getinput() {
  string s;
  getline(cin, s);
  if (s == "ACCESS GRANTED") exit(0);
  s = s.substr(15, s.size() - 15);
  s = s.substr(0, s.size() - 4);
  cerr << "s: " << s << "\n";
  return stoi(s);
}

int main() {
  vector<char> cs;
  for (char c = '0'; c <= '9'; ++c) cs.push_back(c);
  for (char c = 'A'; c <= 'Z'; ++c) cs.push_back(c);
  for (char c = 'a'; c <= 'z'; ++c) cs.push_back(c);
  int mx = 0;
  int len = 0;
  for (int i = 1; i <= 20; ++i) {
    cout << string(i, 'a') << endl; fflush(stdout);
    int t = getinput();
    if (t > mx) {
      mx = t;
      len = i;
    }
  }
  string s(len, 'a');
  for (int i = 0; i < len; ++i) {
    mx = 0;
    char b = ' ';
    for (char c : cs) {
      s[i] = c;
      cout << s << endl; fflush(stdout);
      int t = getinput();
      if (t > mx) {
        mx = t;
        b = c;
      }
    }
    s[i] = b;
  }
  cout << s << endl;
}
