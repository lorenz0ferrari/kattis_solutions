#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

clock_t tbegin;
constexpr float TL = 2.9;
int n, k, best = 0;
vector<int> o, ro;
vector<vector<int>> adj;

inline vector<int> intersect(const vector<int>& a, const vector<int>& b) {
	vector<int> ans;
	for (int i = 0, j = 0; i < int(a.size()) && j < int(b.size());) {
		if (a[i] == b[j]) {
			ans.push_back(a[i]);
			++i, ++j;
		} else if (ro[a[i]] < ro[b[j]]) {
			++i;
		} else {
			++j;
		}
	}
	return ans;
}

vector<vector<int>> cur;

void solve(int step, int i = 0) {
	best = max(best, step);
	if (int(cur.back().size()) <= i ||
		step + int(cur.back().size()) <= best ||
		best == k ||
		clock() - tbegin > TL*CLOCKS_PER_SEC) return;
	cur.push_back(intersect(cur.back(), adj[cur.back()[i]]));
	solve(step+1);
	cur.pop_back();
	solve(step, i+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	tbegin = clock();
	cin >> n >> k;
	o.resize(n);
	ro.resize(n);
	adj.resize(n);
	for (int i = 0; i < n; ++i) {
		int d; cin >> d;
		for (int a; d--;) {
			cin >> a;
			adj[i].push_back(a);
		}
	}
	iota(o.begin(), o.end(), 0);
	sort(o.begin(), o.end(), [&](int i, int j){
		return adj[i].size() > adj[j].size();
	});
	cur.push_back(o);
	for (int i = 0; i < n; ++i) ro[o[i]] = i;
	vector<vector<int>> aa(n);
	for (int i = 0; i < n; ++i) {
		for (int j : adj[i]) {
			if (ro[i] < ro[j]) {
				aa[i].push_back(j);
			}
		}
	}
	adj = aa;
	for (auto& x : adj) {
		sort(x.begin(), x.end(), [&](int i, int j){return ro[i]<ro[j];});
	}
	solve(0);
	cout << best << "\n";
}
