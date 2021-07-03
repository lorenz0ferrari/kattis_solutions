#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> p;

string find_set(string &v) {
	return v == p[v] ? v : p[v] = find_set(p[v]);
}

void union_set(string a, string b) {
	a = find_set(a);
	b = find_set(b);

	p[a] = b;
}

struct vin {
	string s1;
	string s2;
	bool r;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	unordered_set<string> words;

	vector<vin> v(n);
	for (vin &i : v) {
		string a, b, c;
		cin >> a >> b >> c;
		i = {a, c, b == "is"};

		words.insert(a);
		words.insert(c);
	}

	unordered_map<string, vector<string>> mp;
	for (string w : words) {
		p[w] = w;

		int sz = w.size();

		if (words.find(w.substr(sz - 1, 1)) != words.end()) {
			mp[w.substr(sz - 1, 1)].push_back(w);
		} else if (words.find(w.substr(sz - 2, 2)) != words.end()) {
			mp[w.substr(sz - 2, 2)].push_back(w);
		} else {
			mp[w.substr(sz - 3, 3)].push_back(w);
		}
	}

	for (auto &x : mp)
		for (string &y : x.second)
			union_set(x.second[0], y);

	for (vin &i : v)
		if (i.r)
			union_set(i.s1, i.s2);

	for (vin &i : v) {
		if (!i.r && find_set(i.s1) == find_set(i.s2)) {
			cout << "wait what?" << "\n";
			return 0;
		}
	}

	cout << "yes" << "\n";
}
