#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int minWeight = 50;

int trips(vector<int> &w) {
	sort(w.begin(), w.end(), greater<int>());
	int cnt = 0, n = w.size(), carried = 0;
	for (int i = 0; carried < n; ++i) {
		if (w[i] >= minWeight) {
			++cnt;
			++carried;
		} else {
			++cnt;
			carried += (minWeight + w[i] - 1) / w[i];
		}
	}
	return max(1, cnt - (carried > n));
}

int main(void) {
	cout.sync_with_stdio(false);
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t) {
		int n;
		cin >> n;
		vector<int> w(n);
		for (int i = 0; i < n; ++i)
			cin >> w[i];
		cout << "Case #" << t << ": " << trips(w) << endl;
	}
	return 0;
}
