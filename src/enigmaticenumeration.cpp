#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<set<int>> adj;

array<LL, 2> solve(int n, int s, int e) {
    vector<array<LL, 2>> d(n, {(LL)1e9, 0});
    queue<int> Q;
    Q.push(s);
    d[s] = {1, 1};
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : adj[v]) {
            if (d[u][0] > d[v][0] + 1) {
                d[u] = {d[v][0] + 1, d[v][1]};
                Q.push(u);
            } else if (d[u][0] == d[v][0] + 1) {
                d[u][1] += d[v][1];
            }
        }
    }
    return d[e];
}

int main() {
    int n; cin >> n;
    int m; cin >> m;
    adj.resize(n);
    vector<array<int, 2>> e(m);
    for (auto& [a, b] : e) {
        cin >> a >> b; --a, --b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    array<LL, 2> ans{n, 0}; // {len, cnt}
    for (auto& [a, b] : e) {
        adj[a].erase(b);
        adj[b].erase(a);
        auto cur = solve(n, a, b);
        if (cur[0] < ans[0]) {
            ans = cur;
        } else if (cur[0] == ans[0]) {
            ans[1] += cur[1];
        }
        adj[a].insert(b);
        adj[b].insert(a);
    }
    assert(ans[1] % ans[0] == 0);
    cout << ans[1] / ans[0] << "\n";
}
