// problem: https://www.acmicpc.net/problem/2042
// hint: segment tree, binary indexed tree, sqrt decomposition
// level: medium
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void update(int i, long long v, vector<long long> &blks) {
	int n = blks.size();
	blks[i/n] += v;
}

long long sum(int l, int r, vector<long long> &v, vector<long long> &blks) {
	int n = blks.size();
	int li = l / n, ri = r / n;
	long long sum = 0;
	if (li == ri) {
		for (int i = l; i <= r; ++i)
			sum += v[i];
	} else {
		for (int i = l, e = (li + 1) * n; i < e; ++i)
			sum += v[i];
		for (int i = li + 1; i < ri; ++i)
			sum += blks[i];
		for (int i = ri * n; i <= r; ++i)
			sum += v[i];
	}
	return sum;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	int units = sqrt(n) + 1;
	vector<long long> v(n);
	vector<long long> block(units);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		update(i, v[i], block);
	}

	for (int i = 0; i < m + k; ++i) {
		int a;
		long long b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c - v[b-1], block);
			v[b-1] = c;
		} else {
			cout << sum(b - 1, c - 1, v, block) << '\n';
		}
	}
	return 0;
}
