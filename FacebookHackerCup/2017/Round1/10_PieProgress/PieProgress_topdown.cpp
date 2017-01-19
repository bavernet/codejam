#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost(int n, int need, const vector<vector<int> > &c, vector<vector<int> > &dp) {
	const vector<int> &bread = c[n];
	int m = bread.size();
	int &ans = dp[n][need];
	if (ans)
		return ans;

	if (!n) {
		if (need > m)
			return ans = 1234567890;
		ans = need * need;
		for (int i = 0; i < need; ++i)
			ans += bread[i];
		return ans;
	}

	int sum = 0;
	int e = min(m, need - n);
	ans = cost(n - 1, need, c, dp);
	for (int i = 1; i <= e; ++i) {
		sum += bread[i-1];
		ans = min(ans, sum + (i * i) + cost(n - 1, need - i, c, dp));
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > dp(n, vector<int>(n + 1));
		vector<vector<int> > c(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cin >> c[i][j];
			sort(c[i].begin(), c[i].end());
		}
		cout << "Case #" << t << ": " << cost(n - 1, n, c, dp) << endl;
	}
	return 0;
}
