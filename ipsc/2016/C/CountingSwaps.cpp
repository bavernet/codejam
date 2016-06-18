#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MOD     (1000000009)
#define m(x)    ((x) % MOD)

long long comb(int n, int r) {
	if (r < 0)
		return 0;
	if (n == r || r == 0)
		return 1;
	return m(comb(n - 1, r - 1) + comb(n - 1, r));
}

long long count(int n) {
	if (n == 1 || n == 2)
		return 1;
	return m(n * count(n - 1));
}

long long solve(vector<int> &p) {
	long long ans = 0;
	int n = p.size();
	int nSwaps = 0;
	vector<int> grp;
	for (int i = 0; i < n; ++i) {
		if (!p[i])
			continue;

		int len = 1;
		int next = p[i] - 1;
		p[i] = 0;
		while (p[next] > 0) {
			int prev = next;
			next = p[next] - 1;
			p[prev] = 0;
			++len;
		}

		nSwaps += len - 1;
		if (len > 1)
			grp.push_back(len);
	}

	ans = 1;
	for (int len : grp) {
		ans = m(ans * count(len));
		ans = m(ans * comb(nSwaps, len - 1));
		nSwaps -= len - 1;
	}

	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		cout << solve(p) << endl;
	}

	return 0;
}
