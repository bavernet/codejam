// problem: https://algospot.com/judge/problem/read/TRIANGLEPATH
// hint: dp
// level: easy
#include <iostream>
#include <vector>

using namespace std;

int getMaxPathSum(int i, int j,
				  vector<vector<int> > &tri, vector<vector<int> > &dp) {
	if (i + 1 == tri.size())
		return tri[i][j];
	int &ans = dp[i][j];
	if (ans)
		return ans;
	ans = getMaxPathSum(i + 1, j, tri, dp);
	ans = max(ans, getMaxPathSum(i + 1, j + 1, tri, dp));
	return ans += tri[i][j];
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		vector<vector<int> > tri(n), dp(n);
		for (int i = 0; i < n; ++i) {
			tri[i].resize(i + 1);
			dp[i].resize(i + 1);
			for (int j = 0; j < i + 1; ++j) {
				cin >> tri[i][j];
			}
		}

		cout << getMaxPathSum(0, 0, tri, dp) << endl;
	}

	return 0;
}
