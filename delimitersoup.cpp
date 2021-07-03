#include <bits/stdc++.h>
using namespace std;

int find_nxt(int i, int n, vector<int> &nxt) {
  return (i >= n || nxt[i] == i) ? i : nxt[i] = find_nxt(nxt[i], n, nxt);
}

bool cmpl(char a, char b) {
  return (a == '(' && b == ')') ||
         (a == '[' && b == ']') ||
         (a == '{' && b == '}');
}

int main() {
  string s;

  getline(cin, s);
  int n = stoi(s);

  getline(cin, s);

  vector<int> nxt(n);
  for (int i = 0; i < n; i++)
    nxt[i] = s[i] != ' ' ? i : i + 1;

  bool swapped = true;
  while (swapped) {
    swapped = false;

    for (int i = 0; i < n; i = find_nxt(i + 1, n, nxt)) {
      if (s[i] == ' ')
        continue;
      int j = find_nxt(i + 1, n, nxt);
      if (j < n) {
        if (cmpl(s[i], s[j])) {
          s[i] = ' '; nxt[i] = j;
          s[j] = ' '; nxt[j] = find_nxt(j + 1, n, nxt);
          swapped = true;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == ')' || c == ']' || c == '}') {
      cout << c << " " << i << "\n";
      return 0;
    }
  }

  cout << "ok so far" << "\n";
}
