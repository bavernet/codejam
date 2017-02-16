// problem: http://codeforces.com/contest/765/problem/D
// hint: dsu, math
// level: moderate
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool split(const vector<int> &f, vector<int> &h, vector<int> &g) {
	int n = f.size() - 1;
	map<int,vector<int> > m;
	for (int i = 1; i <= n; ++i)
		m[f[i]].push_back(i);

	g.resize(n);
	int i = 1;
	for (const auto &p : m) {
		int r = p.first;
		const vector<int> &a = p.second;
		if (!binary_search(a.begin(), a.end(), r))
			return false;
		h.push_back(r);
		for (auto ai : a)
			g[ai-1] = i;
		++i;
	}
	return true;
}

int main(void) {
	cout.sync_with_stdio(false);
	int n = 0;
	cin >> n;
	vector<int> f(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> f[i];

	vector<int> h, g;
	if (split(f, h, g)) {
		cout << h.size() << endl;
		for (auto gi : g)
			cout << gi << ' ';
		cout << endl;

		for (auto hi : h)
			cout << hi << ' ';
		cout << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
