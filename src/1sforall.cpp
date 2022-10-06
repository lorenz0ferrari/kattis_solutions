#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
using LL = long long;

int main() {
    LL p[15]; p[0] = 1;
    for (int i = 1; i < 15; ++i) {
        p[i] = p[i - 1]*10;
    }
    auto len = [&](int n) -> int {
        int cnt = 0;
        while (n) {
            ++cnt;
            n /= 10;
        }
        return cnt;
    };

    LL n; cin >> n;
    vector<int> d(10*n, 100);
    vector<vector<int>> dd(n+1);

    auto combine = [&](LL a, LL b, LL w) -> void {
        if (a + b <= n && d[a + b] > w) { d[a + b] = w; dd[w].push_back(a + b); }
        if (a * b <= n && d[a * b] > w) { d[a * b] = w; dd[w].push_back(a * b); }
        LL c = a*p[len(b)] + b;
        if (c <= n && d[c] > w) {
            d[c] = w;
            dd[w].push_back(c);
        }
    };

    d[1] = 1; dd[1].push_back(1);
    for (int w = 2; d[n] == 100; ++w) {
        for (int a = 1; a < w; ++a) {
            for (int i : dd[a]) for (int j : dd[w - a]) {
                combine(i, j, w);
            }
        }
    }
    cout << d[n] << "\n";
}
