// problem: https://algospot.com/judge/problem/read/TRIANGLEPATH
// hint: dp
// level: easy
#include <iostream>
#include <vector>

using namespace std;

int getMaxPathSum(vector<vector<int> > &tri) {
	int n = tri.size();
	vector<int> sum(tri.back().begin(), tri.back().end());
	for (int i = n - 1; i > 0; --i)
		for (int j = 0; j + 1 < tri[i].size(); ++j)
			sum[j] = max(sum[j], sum[j+1]) + tri[i-1][j];
	return sum[0];
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		vector<vector<int> > tri(n);
		for (int i = 0; i < n; ++i) {
			tri[i].resize(i + 1);
			for (int j = 0; j < i + 1; ++j) {
				cin >> tri[i][j];
			}
		}

		cout << getMaxPathSum(tri) << endl;
	}

	return 0;
}
