// problem: http://codeforces.com/contest/761/problem/D
// hint: greedy
// level: moderate
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool findB(const vector<int> &a, const vector<int> &p, int l, int r,
		   vector<int> &b) {
	int n = a.size();
	vector<int> cl(n), cr(n);
	for (int i = 0; i < n; ++i) {
		cl[p[i]-1] = l - a[i];
		cr[p[i]-1] = r - a[i];
	}
	for (int i = 1; i < n; ++i) {
		cl[i] = max(cl[i-1] + 1, cl[i]);
		if (cl[i] > cr[i])
			return false;
	}
	for (int i = 0; i < n; ++i)
		b[i] = a[i] + cl[p[i]-1];
	return true;
}

int main(void) {
	cout.sync_with_stdio(false);
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n), p(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> p[i];

	vector<int> b(n);
	if (!findB(a, p, l, r, b)) {
		cout << -1 << endl;
	} else {
		for (auto bi : b)
			cout << bi << ' ';
		cout << endl;
	}

	return 0;
}
