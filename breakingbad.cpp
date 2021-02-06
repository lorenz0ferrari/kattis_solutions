#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;

map <string, int> StoI;
map <int, string> ItoS;

vector <int> who;
vector <vector<int>> g;

void dfs(int v) {
  for (int u : g[v]) {
    if (who[v] == who[u]) {
      cout << "impossible" << "\n";
      exit(0);
    } else if (who[u] == -1) {
      who[u] = 1 ^ who[v];
      dfs(u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  g.resize(n);
  who.assign(n, -1);

  string a, b;
  for (int i = 0; i < n; i++) {
    cin >> a;
    StoI[a] = i;
    ItoS[i] = a;
  }

  int m;
  cin >> m;
  for (int i = 0, v, u; i < m; i++) {
    cin >> a >> b;
    v = StoI[a];
    u = StoI[b];
    g[v].push_back(u);
    g[u].push_back(v);
  }

  for (int i = 0; i < n; i++) {
    if (who[i] == -1) {
      who[i] = 1;
      dfs(i);
    }
  }

  vector <string> walter;
  vector <string> jesse;

  for (int i = 0; i < n; i++) {
    if (who[i]) {
      walter.push_back(ItoS[i]);
    } else {
      jesse.push_back(ItoS[i]);
    }
  }

  for (string s : walter)
    cout << s << " ";
  cout << "\n";

  for (string s : jesse)
    cout << s << " ";
  cout << "\n";
}
