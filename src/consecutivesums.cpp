#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(LL n) {
    int nn = 2*n;
    int kk = -1;
    auto f = [&](int k) -> void {
        int a = (nn / (k+1) - k) / 2;
        if (!k || a < 0 || (2*a + k)*(k+1) != nn) return;
        if (kk == -1 || kk > k) {
            kk = k;
        }
    };
    for (int i = 2; i*i <= nn; ++i) {
        if (nn % i) continue;
        f(i - 1);
        f(nn / i - 1);
    }
    if (kk == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        int a = (nn / (kk+1) - kk) / 2;
        cout << n << " = ";
        for (int i = 0; i < kk; ++i) {
            cout << a+i << " + ";
        }
        cout << a+kk << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        solve(n);
    }
}
