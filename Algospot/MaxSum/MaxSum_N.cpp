// problem: https://algospot.com/judge/problem/read/MAXSUM
// hint: dp
// level: moderate
#include <iostream>
#include <vector>

using namespace std;

int getMaxSum(const vector<int> &a) {
	int sum = 0, ans = 0, n = a.size();

	for(int i = 0; i < n; ++i) {
		sum = max(a[i], a[i] + sum);
		ans = max(ans, sum);
	}

	return ans;
}

int main(void) {
	int nTests, n;

	cin >> nTests;
	while (nTests--) {
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		cout << getMaxSum(a) << endl;
	}

	return 0;
}
