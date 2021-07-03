#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int n;
int tot;
vector <int> a;
vector <int> b;

set <int> seen;
map <int, int> valToId;
map <int, int> idToVal;

vector <vector<int>> g;
vector <vector<bool>> c;

inline bool dfs(int &s, int &e, vector <int> &par) {
  fill(par.begin(), par.end(), -1);
  stack <int> st;
  st.push(s);

  while (!st.empty()) {
    int v = st.top();
    st.pop();

    for (int &u : g[v]) {
      if (par[u] == -1 && c[v][u]) {
        par[u] = v;
        if (u == e)
          return 1;
        st.push(u);
      }
    }
  }

  return 0;
}

inline int maxflow(int s, int e) {
  int flow = 0;
  vector <int> par(tot);

  while (dfs(s, e, par)) {
    flow++;
    int cur = e;
    while (cur != s) {
      int prv = par[cur];
      c[cur][prv] = 1;
      c[prv][cur] = 0;
      cur = prv;
    }
  }

  return flow;
}

void restore(int val, int x, int y) {
  if (val == x + y) {
    cout << x << " + " << y << " = " << val << "\n";
  } else if (val == x - y) {
    cout << x << " - " << y << " = " << val << "\n";
  } else if (val == x * y) {
    cout << x << " * " << y << " = " << val << "\n";
  } else {
    assert(false);
  }
}

void print() {
  for (int i = 1; i <= n; i++) {
    for (int id : g[i]) {
      if (!c[i][id]) {
        restore(idToVal[id], a[i-1], b[i-1]);
        break;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  a.resize(n);
  b.resize(n);

  tot = n + 2;
  for (int i = 0, val; i < n; i++) {
    cin >> a[i] >> b[i];

    val = a[i] + b[i];
    if (seen.find(val) == seen.end()) {
      valToId[val] = seen.size() + n + 1;
      idToVal[seen.size() + n + 1] = val;
      seen.insert(val);
      tot++;
    }

    val = a[i] - b[i];
    if (seen.find(val) == seen.end()) {
      valToId[val] = seen.size() + n + 1;
      idToVal[seen.size() + n + 1] = val;
      seen.insert(val);
      tot++;
    }

    val = a[i] * b[i];
    if (seen.find(val) == seen.end()) {
      valToId[val] = seen.size() + n + 1;
      idToVal[seen.size() + n + 1] = val;
      seen.insert(val);
      tot++;
    }
  }

  g.resize(tot);
  c.assign(tot, vector <bool> (tot));

  for (int i = 1; i <= n; i++) {
    g[0].push_back(i); c[0][i] = 1;
    g[i].push_back(0); // c[i][0] = 1;
  }

  for (int i = n+1; i < tot - 1; i++) {
    g[tot-1].push_back(i); // c[tot-1][i] = 1;
    g[i].push_back(tot-1); c[i][tot-1] = 1;
  }

  for (int i = 0, val; i < n; i++) {
    val = a[i] + b[i];
    val = valToId[val];
    g[i+1].push_back(val); c[i+1][val] = 1;
    g[val].push_back(i+1); // c[val][i+1] = 1;

    val = a[i] - b[i];
    val = valToId[val];
    g[i+1].push_back(val); c[i+1][val] = 1;
    g[val].push_back(i+1); // c[val][i+1] = 1;

    val = a[i] * b[i];
    val = valToId[val];
    g[i+1].push_back(val); c[i+1][val] = 1;
    g[val].push_back(i+1); // c[val][i+1] = 1;
  }

  if(maxflow(0, tot-1) < n) {
    cout << "impossible" << "\n";
  } else {
    print();
  }
}
