// problem: https://www.acmicpc.net/problem/12865
// hint: dp, backpack
// level: medium
#include <iostream>
#include <vector>
using namespace std;

int backpack(int k, const vector<int> &w, const vector<int> &v) {
	int n = w.size();
	vector<int> dp(k + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = k - w[i]; j >= 0; --j) {
			if (dp[j+w[i]] < dp[j] + v[i])
				dp[j+w[i]] = dp[j] + v[i];
		}
	}
	return dp[k];
}

int main(void) {
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; ++i)
		cin >> w[i] >> v[i];
	cout << backpack(k, w, v) << endl;
	return 0;
}
