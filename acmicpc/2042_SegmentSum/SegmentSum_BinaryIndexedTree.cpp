// problem: https://www.acmicpc.net/problem/2042
// hint: segment tree, binary indexed tree, sqrt decomposition
// level: medium
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void update(int i, long long v, vector<long long> &bit) {
	int n = bit.size();
	while (i < n) {
		bit[i] += v;
		i += (i & -i);
	}
}

long long sum(int i, vector<long long> &bit) {
	long long sum = 0;
	while (i) {
		sum += bit[i];
		i -= (i & -i);
	}
	return sum;
}

long long sum(int l, int r, vector<long long> &bit) {
	return sum(r, bit) - sum(l - 1, bit);
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> v(n + 1);
	vector<long long> bit(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		update(i, v[i], bit);
	}

	for (int i = 0; i < m + k; ++i) {
		int a;
		long long b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c - v[b], bit);
			v[b] = c;
		} else {
			cout << sum(b, c, bit) << '\n';
		}
	}
	return 0;
}
