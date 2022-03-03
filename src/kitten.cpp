#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int k; cin >> k;
  vector<vector<int>> adj(105);
  vector<int> par(100, -1);
  for (string line; getline(cin, line);) {
    if (line == "-1") break;
    istringstream ss(line);
    int a; ss >> a;
    for (int b; ss >> b;) {
      adj[a].push_back(b);
      par[b] = a;
    }
  }
  while (k != -1) {
    cout << k << " ";
    k = par[k];
  }
  cout << "\n";
}
