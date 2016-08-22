// problem: https://algospot.com/judge/problem/read/LIS
// hint: dp, binary-search
// level: easy
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxLIS(vector<int> &seq) {
	int n = seq.size();
	vector<int> lis;
	for (int i = 0; i < n; ++i) {
		vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), seq[i]);
		if (it != lis.end())
			*it = seq[i];
		else
			lis.push_back(seq[i]);
	}
	return lis.size();
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
