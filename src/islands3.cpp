#include <bits/stdc++.h>
using namespace std;

const int N = 102;

int n, m;
char g[N][N];
bool vis[N][N];

void dfs(int i, int j, char c) {
  vis[i][j] = true;

  if (i > 0   && g[i-1][j  ] == c && !vis[i-1][j  ]) dfs(i-1, j  , c);
  if (j > 0   && g[i  ][j-1] == c && !vis[i  ][j-1]) dfs(i  , j-1, c);
  if (i < n-1 && g[i+1][j  ] == c && !vis[i+1][j  ]) dfs(i+1, j  , c);
  if (j < m-1 && g[i  ][j+1] == c && !vis[i  ][j+1]) dfs(i  , j+1, c);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> g[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == 'L')
        dfs(i, j, 'C');

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j]) {
        g[i][j] = 'L';
        vis[i][j] = false;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && g[i][j] == 'L') {
        ans++;
        dfs(i, j, 'L');
      }
    }
  }

  cout << ans << endl;
}
