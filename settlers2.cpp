// da finire
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;

bool special(int n) {
  if (n % 6 != 0)
    return false;

  n /= 3;
  int rad = sqrt(n);

  return n == rad * (rad + 1);
}

void choose(int i, int v[], int freq[]) {
  if (i == 0) {v[i] = 1; return;}

  vector <int> cant;
  if (special(i)) {
    // i == 6 * (n)*(n+1)/2 for some n
    // i is the last tile of the current hexagon
    // floor(sqrt(n / 3)) is the side of the curent hexagon
    int rad = sqrt(i / 3);
    cant.push_back(i - 1);
    cant.push_back(3 * (rad - 1) * rad);
    cant.push_back(3 * (rad - 1) * rad + 1);
  } else {
    cant.push_back(i - 1);
    // cant.push_back() // ?
    // cant.push_back() // ?
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // init();
  int v[10000]{};
  int f[6]{};

  for (int i = 0; i < 10000; i++)
    choose(i, v, f);
  //

  int c;
  cin >> c;
  for (int n; c; c--) {
    cin >> n;
    cout << v[n - 1] << "\n";
  }
}








/*
1 -> {}
2 -> {1}
3 -> {1,2}
4 -> {1,3}
5 -> {1,4}
6 -> {1,5}
7 -> {1,2,6}
8 -> {2,7}
9 -> {}

*/
