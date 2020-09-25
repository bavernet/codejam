// problem: https://www.acmicpc.net/problem/9663
// hint: backtrace, bruteforce
// level: medium
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

static inline bool valid(int k, const vector<int> &q) {
	for (int i = 0; i < k; ++i)
		if (abs(q[k] - q[i]) == k - i)
			return false;
	return true;
}

int nqueen(int k, vector<int> &q) {
	int n = q.size();
	if (k == n)
		return 1;

	int ans = 0;
	if (valid(k, q))
		ans = nqueen(k + 1, q);
	for (int i = k + 1; i < n; ++i) {
		swap(q[k], q[i]);
		if (valid(k, q))
			ans += nqueen(k + 1, q);
		swap(q[k], q[i]);
	}
	return ans;
}

int nqueen(int n) {
	vector<int> q(n);
	iota(q.begin(), q.end(), 0);
	return nqueen(0, q);
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << nqueen(n) << endl;
	return 0;
}
