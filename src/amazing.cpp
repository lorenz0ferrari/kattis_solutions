#include <bits/stdc++.h>
using namespace std;

int main() {
  set<array<int, 2>> seen;
  auto vis = [&](int i, int j) -> bool {
    return seen.find({i, j}) != seen.end();
  };
  auto ask = [&](string text) -> bool {
    cout << text << endl;
    string res; cin >> res;
    if (res == "solved" || res == "wrong") exit(0);
    return res == "ok";
  };
  auto dfs = [&](auto&& self, int i, int j) -> void {
    assert(!vis(i, j));
    seen.insert({i, j});
    if (!vis(i+1, j) && ask("up")) { self(self, i+1, j); ask("down"); }
    if (!vis(i-1, j) && ask("down")) { self(self, i-1, j); ask("up"); }
    if (!vis(i, j+1) && ask("right")) { self(self, i, j+1); ask("left"); }
    if (!vis(i, j-1) && ask("left")) { self(self, i, j-1); ask("right"); }
  };
  dfs(dfs, 0, 0);
  cout << "no way out" << "\n";
}
