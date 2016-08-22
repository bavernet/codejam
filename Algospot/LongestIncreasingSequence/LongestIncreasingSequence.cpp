// problem: https://algospot.com/judge/problem/read/LIS
// hint: dp
// level: easy
#include <iostream>
#include <vector>

using namespace std;

int getMaxLIS(vector<int> &seq) {
	int n = seq.size();
	vector<int> len(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		len[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (seq[j] < seq[i]) {
				len[i] = max(len[i], len[j] + 1);
			}
		}
		ans = max(ans, len[i]);
	}
	return ans;
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		vector<int> seq(n);
		for (int i = 0; i < n; ++i)
			cin >> seq[i];
		cout << getMaxLIS(seq) << endl;
	}
	return 0;
}
