#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;

int solve(int n, int m) {
    vector<vi> d(n, vi (n, 1e9));
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    function<void(vector<vi>&, int)> tsp = [&](vector<vi>& dp, int s) {
        dp[1 << s][s] = 0;
        for (int i = 1; i < (1 << n); ++i) {
            if (!(i & (1 << s))) continue;
            for (int j = 0; j < n; ++j) {
                if (!(i & (1 << j))) continue;
                for (int k = 0; k < n; ++k) {
                    if (i & (1 << k)) continue;
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + d[j][k]);
                }
            }
        }
    };

    vector<vi> s(1 << n, vi (n, 1e9)); tsp(s, 0);
    vector<vi> e(1 << n, vi (n, 1e9)); tsp(e, n - 1);

    int ans = 1e9;
    for (int i = 0; i < (1 << (n - 1)); i += 2) {
        if (__builtin_popcount(i) == (n - 2) / 2) {
            int a = 1e9;
            int b = 1e9;
            int s1 = i;
            int s2 = ((1 << (n - 1)) - 2) ^ i;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    a = min(a, s[s1 | 1][j] + d[j][k] + e[s2 | (1 << (n - 1))][k]);
                    b = min(b, e[s1 | (1 << (n - 1))][j] + d[j][k] + s[s2 | 1][k]);
                }
            }
            ans = min(ans, a + b);
        }
    }

    return ans;
}

int32_t main() {
    int n, m;
    for (int i = 1; cin >> n >> m; ++i) {
        cout << "Case " << i << ": " << solve(n, m) << "\n";
    }
}
