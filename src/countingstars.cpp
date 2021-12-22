#include <bits/stdc++.h>
using namespace std;

bool m[101][101];
bool vis[101][101];
int a, b, caso = 0;

void dfs(int i, int j) {
    if(i<0 || j<0 || i>=a || j>=b) return;
    if(vis[i][j] || !m[i][j])
        return;
    vis[i][j] = 1;
    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main() {

    for(int i = 0; i < 101; i++) for(int j = 0; j < 101; j++) m[i][j] = 0;

    while(cin >> a >> b) {
        caso++;
        for(int i = 0; i <= 100; i++) for(int j = 0; j <= 100; j++) { m[i][j] = 0; vis[i][j] = 0;}
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                char temp;
                cin >> temp;
                if(temp == '-')
                    m[i][j] = 1;
            }
        }
        int counter = 0;

        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                if(m[i][j] && !vis[i][j]) {
                    dfs(i, j);
                    counter++;
                }
            }
        }
        cout << "Case " << caso << ": " << counter << "\n";
    }
}
