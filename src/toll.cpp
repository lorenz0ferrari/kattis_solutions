#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int INF = 1e9;
const int LOG = 17;

struct mat {
	int n;
	vector<vector<LL>> a;
	mat(int n) : n(n) {
		a.assign(n, vector<LL>(n, INF));
	}
	void make_unit() {
		for (int i = 0; i < n; ++i) a[i][i] = 0;
	}
	mat operator*(mat oth) const {
		mat ans(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					ans.a[i][j] = min(ans.a[i][j], a[i][k] + oth.a[k][j]);
				}
			}
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k; cin >> k;
	int n; cin >> n;
	int m; cin >> m;
	int o; cin >> o;
	int nn = (n + k - 1) / k;
	vector<vector<mat>> up(nn, vector<mat>(LOG, mat(k)));
	for (int i = 0, a, b, t; i < m; ++i) {
		cin >> a >> b >> t;
		up[a/k][0].a[a%k][b%k] = min(up[a/k][0].a[a%k][b%k], (LL)t);
	}
	for (int i = 1; i < LOG; ++i) {
		for (int j = 0; j < nn; ++j) {
			int oth = min(nn-1, j + (1 << (i-1)));
			up[j][i] = up[j][i-1]*up[oth][i-1];
		}
	}
	for (int i = 0, a, b; i < o; ++i) {
		cin >> a >> b;
		mat cur(k); cur.make_unit();
		int ka = a / k;
		int kb = b / k;
		int s = kb - ka;
		for (int j = LOG-1; j >= 0; --j) {
			if (s >= (1 << j)) {
				cur = cur * up[ka][j];
				ka += 1 << j;
				s -= 1 << j;
			}
		}
		int ans = cur.a[a%k][b%k];
		cout << (ans >= INF ? -1 : ans) << "\n";
	}
}
