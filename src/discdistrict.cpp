#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct pt {
    LL x, y;
};

int main() {
    LL r; cin >> r;
    pt ans{0, r+1};
    auto d = [&](pt p) -> LL {
        return p.x*p.x + p.y*p.y;
    };
    pt cur = ans;
    while (cur.y != 0) {
        --cur.y;
        while (d(cur) <= r*r) {
            ++cur.x;
        }
        if (d(cur) < d(ans)) {
            ans = cur;
        }
    }
    cout << ans.x << " " << ans.y << "\n";
}
