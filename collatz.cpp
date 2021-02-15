#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;

void solve(int64_t A, int64_t B) {
  int64_t a = A;
  int64_t b = B;
  unordered_map<int64_t, int64_t> vis;

  vis[a] = 1;
  for (int i = 2; a != 1; i++) {
    if (a % 2 == 1)
      a = a * 3 + 1;
    else
      a = a / 2;
    vis[a] = i;
  }

  int ab = 1;
  for (; !vis[b]; ab++) {
    if (b % 2 == 1)
      b = b * 3 + 1;
    else
      b = b / 2;
  }

  cout << A << " needs " << vis[b] - 1 << " steps, ";
  cout << B << " needs " << ab - 1     << " steps, ";
  cout << "they meet at "<< b          << endl;

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0)
      break;
    solve(a, b);
  }
}