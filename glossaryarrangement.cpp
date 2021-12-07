#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, w;
vector<int> l;
vector<string> s;

bool possible(int h) {
  vector<int> dp(n, 1e9);
  vector<int> jj(n, -1);
  dp[0] = l[0];
  for (int i = 1; i < n; ++i) {
    if (i < h) {
      dp[i] = *max_element(l.begin(), l.begin() + i + 1);
      jj[i] = -1;
    }
    int mx = 0;
    for (int j = i - 1; j >= 0 && j >= i - h; --j) {
      mx = max(mx, l[j + 1]);
      if (dp[i] > 1 + dp[j] + mx) {
        dp[i] = 1 + dp[j] + mx;
        jj[i] = j;
      }
    }
  }
  return dp[n - 1] <= w;
}

int main() {
#ifdef LORENZO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin >> n >> w;
  s.resize(n);
  l.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    l[i] = s[i].size();
  }
  int ll = 0, r = n;
  while (r - ll > 1) {
    int mid = (ll + r) / 2;
    if (possible(mid))
      r = mid;
    else
      ll = mid;
  }
  vector<int> dp(n, 1e9);
  vector<int> jj(n, -1);
  dp[0] = l[0];
  for (int i = 1; i < n; ++i) {
    if (i < r) {
      dp[i] = *max_element(l.begin(), l.begin() + i + 1);
      jj[i] = -1;
    }
    int mx = 0;
    for (int j = i - 1; j >= 0 && j >= i - r; --j) {
      mx = max(mx, l[j + 1]);
      if (dp[i] > 1 + dp[j] + mx) {
        dp[i] = 1 + dp[j] + mx;
        jj[i] = j;
      }
    }
  }
  int cnt = 0;
  for (int tmp = n - 1; tmp != -1; tmp = jj[tmp], ++cnt);
  vector<int> width(cnt);
  for (int tmp = n - 1, i = 1; tmp != -1; tmp = jj[tmp], ++i) {
    width[cnt - i] = dp[tmp] - (jj[tmp] == -1 ? 0 : dp[jj[tmp]] + 1);
  }
  vector<vector<string>> st(cnt + 1);
  for (int tmp = n - 1, i = 1; tmp != -1; tmp = jj[tmp], ++i) {
    for (int j = jj[tmp] + 1; j <= tmp; ++j)
      st[cnt - i].push_back(s[j]);
  }
  for (int i = 0; i < cnt; ++i) st[i].resize(r);
  cout << r << " " << cnt << endl;
  for (int i : width) cout << i << " ";
  cout << endl;
  for (int j = 0; j < r; ++j) {
    for (int i = 0; i < cnt; ++i) {
      cout << st[i][j] << string(width[i] + 1 - st[i][j].size(), ' ');
    }
    cout << endl;
  }
}
