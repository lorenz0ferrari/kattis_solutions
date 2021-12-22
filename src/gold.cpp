#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> m >> n;

  int x0, y0;
  vector<vector<char>> g(n, vector<char> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'P') {
        x0 = i;
        y0 = j;
      }
    }
  }

  vector<vector<bool>> sensor(n, vector<bool> (m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'T') {
        if (i >   0) sensor[i-1][j  ] = true;
        if (i < n-1) sensor[i+1][j  ] = true;
        if (j >   0) sensor[i  ][j-1] = true;
        if (j < m-1) sensor[i  ][j+1] = true;
      }
    }
  }

  vector<vector<bool>> vis(n, vector<bool> (m));
  queue<pair<int, int>> Q;
  Q.push({x0, y0});
  while (!Q.empty()) {
    int x = Q.front().first;
    int y = Q.front().second;
    Q.pop();

    if (vis[x][y])
      continue;
    vis[x][y] = true;

    if (sensor[x][y])
      continue;

    if (x > 0   && g[x-1][y  ] != '#' && !vis[x-1][y  ]) Q.push({x-1,y  });
    if (x < n-1 && g[x+1][y  ] != '#' && !vis[x+1][y  ]) Q.push({x+1,y  });
    if (y > 0   && g[x  ][y-1] != '#' && !vis[x  ][y-1]) Q.push({x  ,y-1});
    if (y < m-1 && g[x  ][y+1] != '#' && !vis[x  ][y+1]) Q.push({x  ,y+1});
  }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      ans += (vis[i][j] && g[i][j] == 'G');

  cout << ans << endl;
}
