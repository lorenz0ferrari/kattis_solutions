#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;

const int64_t mod = 1e9 + 7;

int64_t fexp(int64_t x, int64_t y) {
	if (y < 0)
		return 0;
	uint64_t ans = 1;
	while (y) {
		if (y & 1)
			ans = (ans * x) % mod;

		y >>= 1;
		x = (x * x) % mod;
	}

	return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = s.size();
	int cnt = (s[0] == '?');

	vector<int> pref(n);
	for (int i = 1; i < n; i++) {
		cnt += (s[i] == '?');
		pref[i] = pref[i - 1];
		pref[i] += (s[i - 1] == '?');
		pref[i] += (s[i - 1] == '1') * 2;
	}

	int64_t ans = 0;
	int64_t p1 = fexp(2, cnt);
	int64_t p2 = fexp(2, cnt - 1);

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			ans = (ans + pref[i] * p1) % mod;
		} else if (s[i] == '?') {
			ans = (ans + pref[i] * p2) % mod;
		}
	}

	cout << (ans * fexp(2, mod - 2)) % mod << "\n";
}
