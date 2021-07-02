#include <bits/stdc++.h>
using namespace std;

std::vector<int> z_algo(std::string s) {
	int n = s.size();
	std::vector<int> Z(n);
	for (int i = 1, L = 0, R = 0; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R - L] == s[R])
				R++;
			Z[i] = R - L;
			R--;
		}
		else {
			if (i + Z[i - L] <= R)
				Z[i] = Z[i - L];
			else {
				L = i; // s[R] != s[R-L+1], sarei andato avanti
				while (R < n && s[R - L] == s[R])
					R++;
				Z[i] = R - L; R--;
			}
		}
	}

	return Z;
}


string F[30];
uint64_t fb[30];
uint64_t a[101];
uint64_t b[101];
uint64_t d[101];
uint64_t e[101];
uint64_t f[101];

uint64_t solve(int n, string p) {
    if (n < 30) {
        auto v = z_algo(p + "#" + F[n]);
        return count(v.begin(), v.end(), p.size());
    }
    int i = 0, sz = p.size();
    for (i; F[i].size() < p.size(); ++i);

    auto Z_p_f1 = z_algo(p + "#" + F[i]);
    auto Z_p_f2 = z_algo(p + "#" + F[i + 1]);
    auto Z_p_f1f2 = z_algo(p + "#" + F[i] + F[i + 1]);
    auto Z_p_f2f1 = z_algo(p + "#" + F[i + 1] + F[i]);
    auto Z_p_f2f2 = z_algo(p + "#" + F[i + 1] + F[i + 1]);

    uint64_t rec1 = 0;
    uint64_t rec2 = 0;
    uint64_t rec12 = 0;
    uint64_t rec21 = 0;
    uint64_t rec22 = 0;
    for (int& i : Z_p_f1) rec1 += i == sz;
    for (int& i : Z_p_f2) rec2 += i == sz;
    for (int& i : Z_p_f1f2) rec12 += i == sz;
    for (int& i : Z_p_f2f1) rec21 += i == sz;
    for (int& i : Z_p_f2f2) rec22 += i == sz;
    rec12 -= rec1 + rec2;
    rec21 -= rec2 + rec1;
    rec22 -= rec2 + rec2;

// fs qualche offbyone
    uint64_t ans = 0;
    ans += rec1 * a[n - i];
    ans += rec2 * b[n - i];
    ans += rec12 * d[n - i];
    ans += rec21 * e[n - i];
    ans += rec22 * f[n - i];

    return ans;
}

int main() {
    a[0] = 1, a[1] = 0;
    b[0] = 0, b[1] = 1;
    F[0] = "0"; fb[0] = 0;
    F[1] = "1"; fb[1] = 1;

    for (int i = 2; i < 30; ++i) {
        F[i] = F[i - 1] + F[i - 2];
        f[i] = f[i - 1] + f[i - 2];
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
        d[i] = d[i - 1] + d[i - 2] + (i & 1);
        e[i] = e[i - 1] + e[i - 2] + (i == 2);
        f[i] = f[i - 1] + f[i - 2] + (i != 2 && !(i & 1));
    }
    for (int i = 30; i <= 100; ++i) {
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
        d[i] = d[i - 1] + d[i - 2] + (i & 1);
        e[i] = e[i - 1] + e[i - 2] + (i == 2);
        f[i] = f[i - 1] + f[i - 2] + (i != 2 && !(i & 1));
    }

    int n;
    string p;
    for (int i = 1; cin >> n >> p; ++i) {
        cout << "Case " << i << ": " << solve(n, p) << "\n";
    }
    cin >> n >> p;
}
