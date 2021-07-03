#include <bits/stdc++.h>
using namespace std;

#define SQ(x) (x)*(x)

void solve(int caso) {
  cout << "Case #" << caso << ": ";
  int x1, x2, x3;
  int y1, y2, y3;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;

  if ((x1 == x2 && y1 == y2) ||
      (x1 == x3 && y1 == y3) ||
      (x2 == x3 && y2 == y3)) {
    cout << "not a triangle" << "\n";
    return;
  }

  if (x1 == x2 && x1 == x3) {
    cout << "not a triangle" << "\n";
    return;
  } else {
    if ((y1 - y2) * (x2 - x3) == (x1 - x2) * (y2 - y3)) {
      cout << "not a triangle" << "\n";
      return;
    }
  }

  int l1 = SQ(x1 - x2) + SQ(y1 - y2);
  int l2 = SQ(x1 - x3) + SQ(y1 - y3);
  int l3 = SQ(x2 - x3) + SQ(y2 - y3);

  bool isosceles = false;
  if (l1 == l2) isosceles = true;
  if (l1 == l3) isosceles = true;
  if (l2 == l3) isosceles = true;

  bool obtuse = false;
  if (l1 > l2 + l3) obtuse = true;
  if (l2 > l1 + l3) obtuse = true;
  if (l3 > l1 + l2) obtuse = true;

  bool right = false;
  if (l1 == l2 + l3) right = true;
  if (l2 == l1 + l3) right = true;
  if (l3 == l1 + l2) right = true;


  cout << ((isosceles) ? "isosceles " : "scalene ")
       << ((obtuse) ? "obtuse " : (right ? "right " : "acute "))
       << "triangle" << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
}
