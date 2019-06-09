// problem: https://www.acmicpc.net/problem/2042
// hint: segment tree, binary indexed tree, sqrt decomposition
// level: medium
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void update(int i, long long v, int l, int r, int node, vector<long long> &tree) {
	if (i < l || i > r)
		return ;

	tree[node] += v;
	if (l != r) {
		int m = (l + r) / 2;
		update(i, v, l, m, node * 2, tree);
		update(i, v, m + 1, r, node * 2 + 1, tree);
	}
}

long long sum(int l, int r, int start, int last, int node, vector<long long> &tree) {
	if (last < l || r < start)
		return 0;
	if (l <= start && last <= r)
		return tree[node];
	int mid = (start + last) / 2;
	long long ans = 0;
	ans += sum(l, r, start, mid, node * 2, tree);
	ans += sum(l, r, mid + 1, last, node * 2 + 1, tree);
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	int h = ceil(log2(n)) + 1;
	vector<long long> v(n + 1);
	vector<long long> tree(1 << h);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		update(i, v[i], 1, n, 1, tree);
	}

	for (int i = 0; i < m + k; ++i) {
		int a;
		long long b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c - v[b], 1, n, 1, tree);
			v[b] = c;
		} else {
			cout << sum(b, c, 1, n, 1, tree) << '\n';
		}
	}
	return 0;
}
