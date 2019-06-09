// problem: https://www.acmicpc.net/problem/13547
// hint: sqrt decomposition, MO's algorithm
// level: medium
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define MAX_N   100000
#define MAX_M   100000
#define MAX_A   1000000

inline bool add(int v, vector<int> &h) {
	return h[v]++ == 0;
}

inline bool sub(int v, vector<int> &h) {
	return --h[v] == 0;
}

vector<int> unique(vector<int> &a, vector<int> &l, vector<int> &r) {
	int n = a.size(), m = l.size();
	int units = sqrt(n) + 1;
	vector<int> ans(m), si(m);
	iota(si.begin(), si.end(), 0);
	sort(si.begin(), si.end(), [&](int i, int j) {
		int li = l[i] / units;
		int lj = l[j] / units;
		return (li == lj)? r[i] < r[j]: li < lj;
	});

	vector<int> h(MAX_A+1);
	int left = 0, right = 0, cnt = 1;
	++h[a[0]];
	for (auto i : si) {
		--l[i], --r[i];
		while (left < l[i])
			if (sub(a[left++], h))
				--cnt;
		while (left > l[i])
			if (add(a[--left], h))
				++cnt;
		while (right < r[i])
			if (add(a[++right], h))
				++cnt;
		while (right > r[i])
			if (sub(a[right--], h))
				--cnt;
		ans[i] = cnt;
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int m;
	cin >> m;
	vector<int> l(m), r(m);
	for (int i = 0; i < m; ++i)
		cin >> l[i] >> r[i];
	const vector<int> &ans = unique(a, l, r);
	for (auto ai : ans)
		cout << ai << '\n';
	return 0;
}
