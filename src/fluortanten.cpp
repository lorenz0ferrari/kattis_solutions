#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n;
	cin >> n;

	vector<int64_t> a;
	for (int64_t i = 0, ai; i < n; i++) {
		cin >> ai;
		if (ai != 0)
			a.push_back(ai);
	}

	int64_t mx = 0;
	int64_t ans = 0;
	int64_t suff = 0;
	for (int64_t i = n - 2; i >= 0; i--) {
		ans += (i + 1) * a[i];
		suff += a[i];
		mx = max(mx, suff);
	}

	cout << ans + mx << "\n";
}
