#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;

const int MAX = 2e5 + 1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bitset <MAX> tiri;
  bitset <MAX> ans;
  bitset <MAX> buche;

  int n;
  cin >> n;

  vector <int> d(n);
  for (int &i : d) {
    cin >> i;
    tiri[i] = 1;
  }

  int m;
  cin >> m;

	for (int i = 0, k; i < m; i++) {
		cin >> k;
		buche[k] = 1;
	}

  for (int i = 0; i < n; i++) {
    ans |= tiri | (tiri << d[i]);
  }

  cout << (ans & buche).count() << "\n";
}
