// problem: https://algospot.com/judge/problem/read/MAXSUM
// hint: divide and conquer
// level: moderate
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxPartialSum(const vector<int> &a, int start, int end) {
	int unit = (start <= end)? 1: -1;
	int sum = 0, ans = 0;
	for (int i = start; i != end; i += unit) {
		sum += a[i];
		ans = max(ans, sum);
	}
	return ans;
}

int maxSum(const vector<int> &a, int start, int end) {
	if (start == end)
		return 0;

	if (start + 1 == end)
		return max(a[start], 0);

	int mid = (start + end) / 2;
	int ans = max(maxSum(a, start, mid), maxSum(a, mid, end));
	return max(ans, maxPartialSum(a, mid - 1, start - 1) + maxPartialSum(a, mid, end));
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		cout << maxSum(a, 0, n) << endl;
	}
	return 0;
}
