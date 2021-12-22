#include <bits/stdc++.h>
using namespace std;

const int N = 260000;
const int INF = 1e9;

int p[N];

int find_set(int v) {
  return p[v] == v ? v : p[v] = find_set(p[v]);
}

void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);

  p[b] = a;
}

int f(int a, int b) {
  return 500 * a + b;
}


int main() {
  int n, m;
  cin >> m >> n;

  vector<vector<int>> g(n, vector<int> (m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> g[i][j];

  for (int i = 0; i < N; i++)
    p[i] = i;

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (x < n-1 && g[x][y] == g[x+1][y  ]) union_set(f(x,y),f(x+1,y  ));
      if (y > 0   && g[x][y] == g[x  ][y-1]) union_set(f(x,y),f(x  ,y-1));
      if (x > 0   && g[x][y] == g[x-1][y  ]) union_set(f(x,y),f(x-1,y  ));
      if (y < m-1 && g[x][y] == g[x  ][y+1]) union_set(f(x,y),f(x  ,y+1));
    }
  }

  vector<bool> sink(N, true);
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      if (x < n-1 && g[x][y] > g[x+1][y  ]) sink[find_set(f(x,y))] = false;
      if (y > 0   && g[x][y] > g[x  ][y-1]) sink[find_set(f(x,y))] = false;
      if (x > 0   && g[x][y] > g[x-1][y  ]) sink[find_set(f(x,y))] = false;
      if (y < m-1 && g[x][y] > g[x  ][y+1]) sink[find_set(f(x,y))] = false;
    }
  }

  int ans = 0;
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < m; ++y)
      ans += sink[find_set(f(x,y))];

  cout << ans << endl;
}
