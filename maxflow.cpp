#include <bits/stdc++.h>
using namespace std;

vector<vector<int64_t>> g;
vector<vector<int64_t>> c;
vector<vector<int64_t>> o;

const int64_t INF = 1LL << 32;
// dijkstra evita i casi cattivi ma con pragma passa così, lol
int64_t dfs(int64_t s, int64_t t, vector<int64_t> &par) {
  fill(par.begin(), par.end(), -1);

  stack<pair<int64_t, int64_t>> st;
  st.push({s, INF});

  while (!st.empty()) {
    int64_t v = st.top().first;
    int64_t flow = st.top().second;
    st.pop();

    for (int64_t u : g[v]) {
      if (par[u] == -1 && c[v][u]) {
        par[u] = v;
        int64_t new_flow = min(flow, c[v][u]);
        if (u == t)
          return new_flow;
        st.push({u, new_flow});
      }
    }
  }

  return 0;
}

int64_t maxflow(int64_t n, int64_t s, int64_t t) {
  int64_t flow = 0;
  int64_t new_flow;
  vector <int64_t> par(n);

  while (new_flow = dfs(s, t, par)) {
    flow += new_flow;

    int64_t cur = t;
    while (cur != s) {
      int64_t prv = par[cur];
      c[prv][cur] -= new_flow;
      c[cur][prv] += new_flow;
      cur = prv;
    }
  }

  return flow;
}

void print(int64_t n, int64_t flow) {
  vector<array<int64_t, 3>> edges;
  for (int64_t i = 0; i < n; i++) {
    for (int64_t j = 0; j < n; j++) {
      if (o[i][j] - c[i][j] > 0) {
        edges.push_back({i, j, o[i][j] - c[i][j]});
      }
    }
  }

  cout << n << " " << flow << " " << edges.size() << "\n";

  for (auto x : edges) {
    cout << x[0] << " " << x[1] << " " << x[2] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t n, m, s, t;
  cin >> n >> m >> s >> t;

  g.resize(n);
  c.assign(n, vector<int64_t> (n));
  o.assign(n, vector<int64_t> (n));

  for (int64_t i = 0, a, b, c_i; i < m; i++) {
    cin >> a >> b >> c_i;
    g[a].push_back(b); c[a][b] = c_i; o[a][b] = c_i;
    g[b].push_back(a);
  }

  print(n, maxflow(n, s, t));
}
