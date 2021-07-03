#include <bits/stdc++.h>
using namespace std;

vector<int> tokenizza(string line) {
  istringstream ss(line); //creo un input stream a partire da una stringa
  vector<int> ans;
  string token;
  while (getline(ss,token,' ')) {
    ans.push_back(stoi(token));
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (getline(cin, s)) {
    auto x = tokenizza(s);
    auto tot = accumulate(x.begin(), x.end(), 0);

    for (int i = 0; i < x.size(); i++) {
      if (x[i] == tot - x[i]) {
        cout << x[i] << "\n";
        break;
      }
    }
  }

}
