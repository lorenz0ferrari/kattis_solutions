#include <bits/stdc++.h>
using namespace std;

char read_and_choose(char b, char c) {
  bool is;
  char where;
  cin >> where >> is;
  if (is) return where;
  return char((int)b + c - where);
}

void read_garbage() {
  char a, b;
  cin >> a >> b;
}

int main() {
  const int ROUNDS = 1000;
  for (int i = 0; i < ROUNDS; ++i) {
    int r = rand() % 3;
    char initial = 'A' + r;
    cout << initial << endl;
    char choice = read_and_choose('A' + (r+1)%3, 'A' + (r+2)%3);
    cout << choice << endl;
    read_garbage();
  }
}
