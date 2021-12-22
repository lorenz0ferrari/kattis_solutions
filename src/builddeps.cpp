#include <bits/stdc++.h>
using namespace std;

vector<string> tokenizza(string line) {
  istringstream ss(line); //creo un input stream a partire da una stringa
  vector<string> ans;
  string token;
  while (getline(ss,token,' ')) {
    ans.push_back(token);
  }

  return ans;
}

vector <vector<int>> g;

vector <bool> vis;

void dfs(int v) {
  vis[v] = true;
  for (int u : g[v])
    if (!vis[u])
      dfs(u);
}

vector <int> deg;
vector <int> ans;
void toposort(int v) {
  ans.push_back(v);
  for (int u : g[v])
    if (--deg[u] == 0)
      toposort(u);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  g.resize(n);
  vis.resize(n);

  set <string> seen;
  map <string, int> StoI;
  map <int, string> ItoS;

  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    auto x = tokenizza(s);
    x[0].pop_back();

    if (seen.find(x[0]) == seen.end()) {
      StoI[x[0]] = seen.size();
      ItoS[seen.size()] = x[0];
      seen.insert(x[0]);
    }

    for (int j = 1, v = StoI[x[0]], u; j < x.size(); j++) {
      if (seen.find(x[j]) == seen.end()) {
        StoI[x[j]] = seen.size();
        ItoS[seen.size()] = x[j];
        seen.insert(x[j]);
      }

      u = StoI[x[j]];

      g[u].push_back(v);
    }
  }

  getline(cin, s);

  dfs(StoI[s]);

  deg.resize(n);
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      for (int j : g[i])
        deg[j]++;
    }
  }

  toposort(StoI[s]);

  for (int i : ans)
    cout << ItoS[i] << "\n";
}
