#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    int n; cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    LL ans = 0;
    for (int i = 1; i < n-1; ++i) {
        if (a[i-1] <= a[i] && a[i] > a[i+1]) {
            int l = i-1;
            int r = i+1;
            while (l != 0 && a[l-1] <= a[l]) --l;
            while (r != n-1 && a[r] >= a[r+1]) ++r;
            ans = max(ans, min(a[i]-a[l], a[i]-a[r]));
        }
    }
    cout << ans << "\n";
}
