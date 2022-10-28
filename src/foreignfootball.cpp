#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr size_t L = 1e6;
constexpr LL mod = 1e9 + 7;
constexpr LL p = 29;

LL fexp(LL x, LL y) {
    LL ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

LL pw[L], inv[L];

struct Hash {
    vector<LL> prf;
    Hash() {}
    Hash(string s) {
        int n = s.size();
        prf.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            prf[i+1] = prf[i] + (s[i] - 'a' + 1) * pw[i];
            prf[i+1] %= mod;
        }
    }
    LL get_hash(int l, int len) { // [l, r)
        LL ans = prf[l+len] - prf[l] + mod;
        ans = ans * inv[l] % mod;
        return ans;
    }
};

int main() {
    pw[0] = inv[0] = 1;
    for (int i = 1; i < L; ++i) {
        pw[i] = pw[i-1] * p % mod;
        inv[i] = fexp(pw[i], mod - 2);
        assert(pw[i] * inv[i] % mod == 1);
    }

    int n; cin >> n;
    vector<vector<Hash>> h(n, vector<Hash>(n));
    vector<vector<string>> ss(n, vector<string>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ss[i][j];
            h[i][j] = Hash(ss[i][j]);
        }
    }
    auto works = [&](int i) -> bool {
        vector<int> sz(n);
        vector<LL> cur(n);
        sz[0] = i;
        cur[0] = h[0][1].get_hash(0, i);

        for (int j = 1; j < n; ++j) {
            sz[j] = ss[0][j].size() - sz[0];
            if (sz[j] <= 0) {
                return false;
            }
            cur[j] = h[0][j].get_hash(sz[0], sz[j]);
        }
        for (int a = 0; a < n; ++a) for (int b = 0; b < n; ++b) {
            if (a == b) continue;
            if ((int)ss[a][b].size() != sz[a] + sz[b]) return false;
            if (h[a][b].get_hash(0, sz[a]) != cur[a]) return false;
            if (h[a][b].get_hash(sz[a], sz[b]) != cur[b]) return false;
        }
        return true;
    };
    int ans = -1;
    for (int i = 1; i < (int)ss[0][1].size(); ++i) {
        if (!works(i)) continue;
        if (ans == -1) ans = i;
        else {
            cout << "MANY\n";
            return 0;
        }
    }

    if (ans == -1) {
        cout << "NONE\n";
        return 0;
    }
    cout << "UNIQUE\n";
    cout << ss[0][1].substr(0, ans) << "\n";
    for (int i = 1; i < n; ++i) {
        cout << ss[0][i].substr(ans) << "\n";
    }
}
