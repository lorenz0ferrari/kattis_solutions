#include <bits/stdc++.h>
using namespace std;

const int nax = 1042;
const int INF = 1e9;

bool p[nax][nax];
int vis[nax][nax];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y, d, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p[x][y] = true;
    }

    for (int i = 0; i < nax; i++) for (int j = 0; j < nax; j++) vis[i][j] = INF;

    priority_queue <array<int, 3>> Q; // {-distance, x, y}
    Q.push({0, x, y});
    vis[x][y] = 0;
    p[x][y] = false;

    while (!Q.empty()) {
        d = -Q.top()[0];
        x = Q.top()[1];
        y = Q.top()[2];

        Q.pop();

        if (p[x][y]) {
            ans += d;
            p[x][y] = false;
            d = 0;
        }

        if (y + 1 < nax && vis[x][y + 1] > d + 1) {
            Q.push({-(d + 1), x, y + 1});
            vis[x][y + 1] = d + 1;
        }
        if (y - 1 >= 0 && vis[x][y - 1] > d + 1) {
            Q.push({-(d + 1), x, y - 1});
            vis[x][y - 1] = d + 1;
        }
        if (x + 1 < nax && vis[x + 1][y] > d + 1) {
            Q.push({-(d + 1), x + 1, y});
            vis[x + 1][y] = d + 1;
        }
        if (x - 1 >= 0 && vis[x - 1][y] > d + 1) {
            Q.push({-(d + 1), x - 1, y});
            vis[x - 1][y] = d + 1;
        }
    }

    cout << ans << "\n";
}
