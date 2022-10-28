#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater<double>());
    vector<double> prv(2*n+2, 0);
    vector<double> dp(2*n+2, 0);
    dp[n] = 1;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        swap(prv, dp);
        for (int j = -n+1; j <= n; ++j) {
            dp[j+n] = p[i]*prv[j-1+n] + (1-p[i])*prv[j+1+n];
        }
        double cur = 0;
        for (int i = k; i <= n; ++i) {
            cur += dp[i+n];
        }
        ans = max(ans, cur);
    }
    cout << fixed << setprecision(7) << ans << "\n";
}
