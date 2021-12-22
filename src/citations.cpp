#include <bits/stdc++.h>
using namespace std;

vector<int64_t> k;
vector<int64_t> s;
vector<int64_t> d;
vector<vector<int64_t>> g;

int64_t sons(int64_t v) {
	int64_t ans = 1;
	for (int64_t u : g[v])
		ans += sons(u);

	return s[v] = ans;
}

int64_t delta(int64_t v) {
	int64_t ans = 1 + k[v];
	for (int64_t u : g[v])
		ans += delta(u);
	return d[v] = ans;
}

int64_t dfs(int64_t v, int64_t acc) {
	int64_t ans = acc + 1 + k[v];

	vector<pair<double, int64_t>> c;
	for (int64_t u : g[v]) {
		ans += d[u] + dfs(u, acc + 1);
		c.push_back({1.0 * d[u] / s[u], u});
	}

	sort(c.begin(), c.end());

	int prf = 0;
	for (auto [k, u] : c) {
		ans += prf * s[u];
		prf += d[u];
	}

	return ans;

  return ans + k[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n;
	cin >> n;

	g.resize(n);
	k.resize(n);
	s.resize(n);
	d.resize(n);

	for (int64_t i = 0, f; i < n; i++) {
		cin >> k[i];
		cin >> f;
		for (int64_t j = 0, c; j < f; j++) {
			cin >> c;
			g[i].push_back(c - 1);
		}
	}

	sons(0);
	delta(0);

	cout << dfs(0, 0) << "\n";
}
