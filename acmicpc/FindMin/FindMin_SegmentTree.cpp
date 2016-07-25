// problem: https://www.acmicpc.net/problem/11003
// hint: segment tree
// level: moderate
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int makeTree(const vector<int> &a, vector<int> &tree, int idx, int start, int end) {
	if (start + 1 == end) {
		return tree[idx] = a[start];
	} else {
		int mid = (start + end) / 2;
		return tree[idx] = min(makeTree(a, tree, idx * 2, start, mid),
							   makeTree(a, tree, idx * 2 + 1, mid, end));
	}
}

int findMin(const vector<int> &tree, int idx, int start, int end, int left, int right) {
	if (end <= left || right <= start)
		return INT_MAX;

	if (left <= start && end <= right)
		return tree[idx];

	int mid = (start + end) / 2;
	return min(findMin(tree, idx * 2, start, mid, left, right),
			   findMin(tree, idx * 2 + 1, mid, end, left, right));
}

int main(void) {
	cout.sync_with_stdio(false);
	int N, L;
	cin >> N >> L;

	int H = ceil(log2(N));
	int nNodes = 2 << (H + 1);
	vector<int> A(N), tree(nNodes);
	for (int i = 1; i <= N; ++i)
		cin >> A[i];

	makeTree(A, tree, 1, 1, N + 1);
	for (int i = 1; i <= N; ++i)
		cout << findMin(tree, 1, 1, N + 1, i - L + 1, i + 1) << " ";
	cout << endl;

	return 0;
}
