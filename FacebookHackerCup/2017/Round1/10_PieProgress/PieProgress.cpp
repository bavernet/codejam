#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INV (1234567890)

int cost(int n, int m, const vector<vector<int> > &bc) {
	vector<vector<int> > dp(2, vector<int>(n + 1));
	for (int j = 1; j <= n; ++j)
		dp[0][j] = INV;

	vector<int> &cur = dp[1];
	vector<int> &prev = dp[0];
	for (int i = 1; i <= n; ++i) {
		int b;
		for (b = i; b <= n; ++b) {
			cur[b] = prev[b];
			int s = 0;
			for (int j = 1; j <= m && i - 1 <= b - j; ++j) {
				s += bc[i-1][j-1];
				int c = s + (j * j) + prev[b-j];
				cur[b] = min(cur[b], c);
			}
		}
		swap(cur, prev);
	}
	return prev[n];
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > bc(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cin >> bc[i][j];
			sort(bc[i].begin(), bc[i].end());
		}
		cout << "Case #" << t << ": " << cost(n, m, bc) << endl;
	}
	return 0;
}
